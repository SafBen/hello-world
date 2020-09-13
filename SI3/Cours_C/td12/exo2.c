#include <stdlib.h>
#include <stdio.h>

typedef enum{ carre , rond , triangle } forme;

typedef struct noeud {
  forme f;
  struct noeud *suivant;
} * ListeDeFormes;

ListeDeFormes lf;

void afficherForme(forme f) {
  switch(f) {
    case carre : printf("carré\n"); break;
    case rond : printf("rond\n"); break;
    case triangle : printf("triangle\n"); break;
    default : printf("forme  inconnue\n");
  }
}

void afficherListedeFormes(ListeDeFormes lf){
  while (lf!=NULL){
    afficherForme(lf->f);
    lf = lf->suivant;
  }
}

int longueur(ListeDeFormes l){
  int i = 0;
  while (lf!=NULL){
    i++;
    lf = lf->suivant;
  }
  return i;
}

int main(){
  int i;
  ListedeFormes lf;
  i = longueur(lf);
  //  afficherListedeFormes(lf);
  printf("%d\n",i);
  return 1;
}
