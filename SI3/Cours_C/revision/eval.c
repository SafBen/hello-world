#include <stdlib.h>
#include <stdio.h>

struct noeud {
  T elt;
  struct noeud *suivant;
}
  
typedef struct {
  int lg;
  struct noeud *tete;
} LISTE;

int longueur(LISTE l){
  return l.lg;
}

void initListe(LISTE *l){
  l->lg=0;
  l
}

void inserer(LISTE l, int r, T e){
  
