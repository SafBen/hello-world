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
#include <stdbool.h>


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
size_t max(size_t a, size_t b)
{
  return a >= b ? a : b;
}
/* Utilisé si on n'a pas trouvé assez de place */
static void *allocate_core(size_t size)
{
  size_t max_size = max((BLOCKS_TO_ALLOCATE(size)) * HEADER_SIZE, MIN_ALLOCATION * HEADER_SIZE);
  Header *new_data = mysbrk(max_size);
  if (new_data == ((void *)-1))
  {
    return NULL;
  }
  SIZE(new_data) = (max_size);
  NEXT(new_data) = freep;
  internal_free(new_data + 1);
  return freep;
}
/* ====================================================================== */


void *internal_malloc(size_t size)
{
  Header *prevp, *p;
  unsigned blocks = BLOCKS_TO_ALLOCATE(size);
  for (p = NEXT(freep), prevp = freep; SIZE(p) < blocks; prevp = p, p = NEXT(p))
  {
    if (p == freep)
    {
      // on a fait un tour de liste --> pas de place
      if ((p = allocate_core(blocks)) == NULL)
      { // NULL si plus de place en mémoire
        return NULL;
      }
    }
  }
  if (SIZE(p) == blocks)
  {
    NEXT(prevp) = NEXT(p);
  }
  else
  {
    // découpage
    Header *new = p + blocks;
    SIZE(new) = SIZE(p) - blocks;
    NEXT(prevp) = new;
    NEXT(new) = NEXT(p);
  }
  SIZE(p) = blocks;
  return (void *)(p + 1);
}


/* ====================================================================== */


void internal_free(void *ptr)
{
  Header *headerPtr = ptr;
  headerPtr--;
  int headerPtr_blocks = BLOCKS_TO_ALLOCATE(SIZE(headerPtr));
  Header *prevp = NULL;
  Header *p = freep;
  bool has_found = false;
  for (p = NEXT(freep), prevp = freep; p < headerPtr && p != freep; prevp = p, p = NEXT(p))
  {
    if (NEXT(freep) == freep)
      break;
    int prev_blocks = BLOCKS_TO_ALLOCATE(SIZE(prevp));
    if (headerPtr + headerPtr_blocks == p ||
        prevp + prev_blocks == headerPtr)
    {
      has_found = true;
      if (prevp + prev_blocks == headerPtr && headerPtr + headerPtr_blocks != p)
      {
        SIZE(prevp) += SIZE(headerPtr);
        NEXT(headerPtr) = NEXT(prevp);
        NEXT(prevp) = headerPtr;
      }
      else if (headerPtr + headerPtr_blocks == p && prevp + prev_blocks != headerPtr)
      {
        SIZE(headerPtr) += SIZE(p);
        NEXT(headerPtr) = p;
        NEXT(prevp) = headerPtr;
      }
      else
      {                                           
        // zone libre à gauche et à droite,
        SIZE(prevp) += SIZE(headerPtr) + SIZE(p); 
        NEXT(prevp) = NEXT(p);
      }
    }
  }
  if (!has_found)
  { 
    // zone occupée à gauche et à droite.
    NEXT(headerPtr) = p;
    NEXT(prevp) = headerPtr;
  }
}


/* ====================================================================== */

void *internal_calloc(size_t nmemb, size_t size)
{
  size_t byte_size = nmemb * size;
  void *ptr = internal_malloc(byte_size);
  memset(ptr, '\0', byte_size);
  return ptr;
}

void *internal_realloc(void *ptr, size_t size)
{
  // A COMPLETER
  // utilise internal_free et internal_malloc
  return ptr;
}
