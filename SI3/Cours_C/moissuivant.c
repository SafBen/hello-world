#include <stdlib.h>
#include <stdio.h>

int next_mois(int mois) {
  switch (mois) {
  case 1 : printf("janvier\n"); break;
  case 2 : printf("février\n"); break;
  case 3 : printf("mars\n"); break;
  case 4 : printf("avril\n"); break;
  case 5 : printf("mai\n"); break;
  case 6 : printf("juin\n"); break;
  case 7 : printf("juillet\n"); break;
  case 8 : printf("août\n"); break;
  case 9 : printf("septembre\n"); break;
  case 10 : printf("octobre\n"); break;
  case 11 : printf("novembre\n"); break;
  case 12 : printf("décembre\n"); break;
  default : printf(stderr,"mois inconnu\n"); break;
  }

int main (void) {
  int mois;
  scanf("%d",&mois);
  next_mois(mois+1);
}


