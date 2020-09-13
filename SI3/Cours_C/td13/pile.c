#include "pile.h"
#include <assert.h>
#include <stdlib.h>

Pile pilevide(){
  return NULL;
}


Pile empiler(T e, Pile *p){
  struct noeud *q = malloc(sizeof(struct noeud));
  q->elt = e;
  q->suivant=*p;
  return q;
}


// La pile n'est pas vide
int depiler(Pile *p){
  assert(!estvide(*p));
  struct noeud *q = *p;
  *p = q->suivant;
  free(q);
  return p;  
}


// La pile n'est pas vide
T sommet(Pile p){
  assert(!estvide(p));
  return p->elt;
}


int estvide(Pile p){
  return p==NULL;
}
