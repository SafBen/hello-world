/*
 * my-malloc.c 	-- Implementation de malloc, free, calloc, realloc
 *
 * Implémentation first-fit pour malloc
 *
 * Erick Gallesio (2015/06/16)
 * Stéphane Lavirotte et Erick Gallesio (2020/04/06)
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

/* On suppose qu'on ajoute au moins 50 Headers au minimum */
#define MIN_ALLOCATION	      50

/* Pour s'aligner sur des frontieres multiples
 * de la taille du type le plus contraignant
 */
#define MOST_RESTRICTING_TYPE long double
typedef union header {				/* Header de bloc */
    struct {
        size_t size;				/* Taille du bloc */
        union header *ptr;			/* bloc libre suivant */
    } info;
    MOST_RESTRICTING_TYPE dummy;	/* Ne sert qu'a provoquer un alignement */
} Header;
#define HEADER_SIZE sizeof(Header)

#define NEXT(p)			 ((p)->info.ptr)
#define SIZE(p)			 ((p)->info.size)

/* L'unité de découpage de la mémoire est la taille de Header car ça permet de gérer facilement chaînage
   Le programme appelant malloc reçoit un pointeur et utilise la mémoire comme il veut.
   BLOCKS_TO_ALLOCATE renvoie le nombre de blocks nécessaires pour le malloc demandé, en tenant compte du header */
#define BLOCKS_TO_ALLOCATE(size) (1 + (size + HEADER_SIZE - 1) / HEADER_SIZE)

static Header base   = { {0, &base} }; /* Le pointeur de départ: aucune zone allouée */
static Header *freep = &base;          /* freep pointe sur la 1ère zone libre */

/* ====================================================================== */

static int nb_alloc   = 0;		/* Nombre de fois où on alloué     */
static int nb_dealloc = 0;		/* Nombre de fois où on désalloué  */
static int nb_sbrk    = 0;		/* nombre de fois où a appelé sbrk */

/* Utilisé si on n'a pas trouvé assez de place */
static void *allocate_core(size_t size)
{
    // A COMPLETER	
	// fait un appel à sbrk pour allouer la mémoire et 
    // un appel à myfree pour chaîner la zone allouée avec la liste freep
    return freep;
}

void *mymalloc(size_t size)
{
    // A COMPLETER	
	// fait un appel à allocate_core si pas de place dans la liste freep
    return NULL;
}

void myfree(void *ptr)
{
	// A COMPLETER	
	// Libère la zone pointée par ptr en l'insérant dans freep
	// Essai de coller les blocs adjacents à cette zone
	// NOTA : la liste freep est triée par ordre croissant
}

void *mycalloc(size_t nmemb, size_t size)
{
	// A COMPLETER	
	// Utilise mymalloc
}


void *myrealloc(void *ptr, size_t size)
{
    // A COMPLETER	
	// utilise myfree et mymalloc
    return ptr;
}

/* ====================================================================== */
#ifdef MALLOC_DBG
void mymalloc_infos(char *msg)
{
    if (msg) fprintf(stderr, "**********\n*** %s\n", msg);

    fprintf(stderr, "# allocs = %3d - # deallocs = %3d - # sbrk = %3d\n",
            nb_alloc, nb_dealloc, nb_sbrk);

    /* affichage de la zone libre */
    Header *p = freep;
    do {
        fprintf(stderr, "\tBlock @ %p (size=%4ld, next %p)\n", p, SIZE(p), NEXT(p));
        p = NEXT(p);
    } while (p != freep);

    if (msg) fprintf(stderr, "**********\n\n");
}
#endif
