/*
 * my-malloc.c  -- Implementation de malloc, free, calloc, realloc
 *
 * Implémentation first-fit pour malloc
 *
 * Erick Gallesio (2020/04/10)
 * Stéphane Lavirotte (2020/04/16)
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "mymalloc.h"

// ======================================================================
//
//    Définition des fonctions. NE PAS MODIFIER CETTE PREMIERE PARTIE.
//
// ======================================================================

// Les fonctions internes à implémenter
void *internal_malloc(size_t size);
void internal_free(void *ptr);
void *internal_calloc(size_t nmemb, size_t size);
void *internal_realloc(void *ptr, size_t size);

// Les fonctions externes: ces fonctions appellent les fonctions internes
//  que vous avez à écrire en y ajoutant une trace qui est utilisée par
//  to-html et villoc.py pour générer les .html
void *mysbrk(intptr_t increment)
{
  void *ret, *old, *tmp;
  static int first_call = 1;

  if (first_call)
  {
    old = sbrk(0);
    fprintf(stderr, "SYS_brk(0)                    =  %p\n", old);
    first_call = 0;
  }

  ret = sbrk(increment);
  tmp = ret + increment;
  fprintf(stderr, "SYS_brk(%p)                    = %p\n", tmp, tmp);
  return ret;
}

void *mymalloc(size_t size)
{
  void *ret = internal_malloc(size);
  fprintf(stderr, "mymalloc(%ld)                     = %p\n", size, ret);
  return ret;
}

void myfree(void *ptr)
{
  internal_free(ptr);
  fprintf(stderr, "myfree(%p)                    = <void>\n", ptr);
}

void *myrealloc(void *ptr, size_t size)
{
  void *ret = internal_realloc(ptr, size);
  fprintf(stderr, "myrealloc(%p, %ld)                     = %p\n", ptr, size, ret);
  return ret;
}

void *mycalloc(size_t nmemb, size_t size)
{
  void *ret = internal_calloc(nmemb, size);
  fprintf(stderr, "mycalloc(%ld, %ld)                   = %p\n", nmemb, size, ret);
  return ret;
}

// ======================================================================
//
//    Implementation
//
// ======================================================================

/* On suppose qu'on ajoute au moins 50 Headers au minimum */
#define MIN_ALLOCATION 50

/* Pour s'aligner sur des frontieres multiples
 * de la taille du type le plus contraignant
 */
#define MOST_RESTRICTING_TYPE long double
typedef union header { /* Header de bloc */
  struct
  {
    size_t size;       /* Taille du bloc */
    union header *ptr; /* bloc libre suivant */
  } info;
  MOST_RESTRICTING_TYPE dummy; /* Ne sert qu'a provoquer un alignement */
} Header;
#define HEADER_SIZE sizeof(Header)

#define NEXT(p) ((p)->info.ptr)
#define SIZE(p) ((p)->info.size)

/* L'unité de découpage de la mémoire est la taille de Header car ça permet de gérer facilement chaînage
   Le programme appelant malloc reçoit un pointeur et utilise la mémoire comme il veut.
   BLOCKS_TO_ALLOCATE renvoie le nombre de blocks nécessaires pour le malloc demandé, en tenant compte du header */
#define BLOCKS_TO_ALLOCATE(size) (1 + (size + HEADER_SIZE - 1) / HEADER_SIZE)

static Header base = {{0, &base}}; /* Le pointeur de départ: aucune zone allouée */
static Header *freep = &base;      /* freep pointe sur la 1ère zone libre */

/* ====================================================================== */

/* Utilisé si on n'a pas trouvé assez de place */
static void *allocate_core(size_t size)
{
  if (size <= MIN_ALLOCATION)
  {
    sbrk(BLOCKS_TO_ALLOCATE(MIN_ALLOCATION));
  }
  else
  {
    sbrk(BLOCKS_TO_ALLOCATE(size));
  }

  myfree(freep);
  // A COMPLETER
  // fait un appel à sbrk pour allouer la mémoire et
  // un appel à myfree pour chaîner la zone allouée avec la liste freep
  return freep;
}

/* ====================================================================== */

void *internal_malloc(size_t size)
{
  /*
  je parcours la liste
  si je suis sur un bloc de taille >= à la taille souhaitée
  si je suis sur un bloc de taille = à la taille cherchée
  supprimer le bloc de la liste
  retourner le pointeur comme résultat de la fonction
  sinon
  découper le zone et ajouter la zone restante libre à la liste
  retourner le pointeur comme résultat de la fonction
  si j'ai réalisé un tour de liste (donc sans trouver)
  allouer une nouvelle zone à la liste (obtenue par sbrk)
  ajouter la zone à la liste (via un appel à free)
  */
  Header *prevp, *p;
  unsigned blocks = BLOCKS_TO_ALLOCATE(size);
  for (prevp = freep, p = NEXT(freep);; prevp = p, p = NEXT(p))
  {
    if (SIZE(p) >= size)
    {
      if (SIZE(p) == size)
      {
        NEXT(prevp) = NEXT(p);
        return p + 1;
      }
      else
      {
        // SIZE(p) > size --> découpage
        Header *new = p + blocks;
        SIZE(new) = SIZE(p) - blocks;
        NEXT(new) = NEXT(p);
        NEXT(prevp) = new;
        SIZE(p) = blocks;
        return p + 1;
      }
    }
    if ((p = allocate_core(blocks)) == NULL)
        return NULL;
    else{

    }
  }
  // A COMPLETER
  // fait un appel à allocate_core si pas de place dans la liste freep
  return NULL;
}

void *internal_malloc2(size_t size)
{
  Header *p, *prevp;
  unsigned blocks;
  /* Allouer un bloc dont la taille est un multiple de celle d'un header */
  blocks = BLOCKS_TO_ALLOCATE(size);
  /* Chercher un bloc assez gros dans la liste des blocs libres */
  for (prevp = freep, p = NEXT(freep);; prevp = p, p = NEXT(p))
  {
    if (SIZE(p) >= blocks)
    {
      if (SIZE(p) == blocks)
      {
        /* Gagne: c'est juste la bonne taille */
        NEXT(prevp) = NEXT(p);
      }
      else
      {
        /* Découpage par le début du bloc libre 
                NEXT(prevp)=p+size;
                SIZE(NEXT(prevp))=SIZE(p)-size;
                */
        Header *new = p + blocks;
        SIZE(new) = SIZE(p) - blocks;
        NEXT(new) = NEXT(p);
        NEXT(prevp) = new;
        SIZE(p) = blocks;
      }
      return (void *)(p + 1);
    }
    /* Regarder si on a fait un tour complet dans la liste des blocs libres */
    if (p == freep)
    {
      /* Allouer de la memoire et la remettre dans la ronde */
      if ((p = allocate_core(blocks)) == NULL)
        return NULL;
    }
  }
}

/* ====================================================================== */

void internal_free(void *ptr)
{
  // A COMPLETER
  // Libère la zone pointée par ptr en l'insérant dans freep
  // Essai de coller les blocs adjacents à cette zone
  // NOTA : la liste freep est triée par ordre croissant
}

void internal_free2(void *ptr) {
    Header *bp, *p, *prevp;
    /* Ajuster bp sur le debut du bloc */
    bp = ((Header *) ptr) - 1;
    for (prevp = freep, p = NEXT(freep);    ; prevp = p, p = NEXT(p)) {
        if (NEXT(prevp) == freep || p > bp) {
            break;
        }
    }
    /* Essayer de "coller" ce bloc au suivant */
    
    /* Essayer de "coller" ce bloc au precedent */
    
}

/* ====================================================================== */

void *internal_calloc(size_t nmemb, size_t size)
{
  // A COMPLETER
  // Utilise internal_malloc
}

void *internal_realloc(void *ptr, size_t size)
{
  // A COMPLETER
  // utilise internal_free et internal_malloc
  return ptr;
}
