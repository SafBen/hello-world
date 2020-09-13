#include <stdlib.h>
#include <stdio.h>

typedef enum{ carre , rond , triangle } forme;

void afficherForme(forme f) {
  switch(f) {
    case carre : printf("carré\n"); break;
    case rond : printf("rond\n"); break;
    case triangle : printf("triangle\n"); break;
    default : printf("forme  inconnue\n");
  }
}

int main(){
  forme *p = malloc(sizeof(forme));
  forme *q = malloc(sizeof(forme));
  forme *r = malloc(sizeof(forme));
  *p = carre;
  *q = rond;
  *r = *p;
  afficherForme(*p);
  afficherForme(*q);
  afficherForme(*r);
  *p = triangle;
  afficherForme(*r);
  free(p);
  afficherForme(*p);
  afficherForme(*r);
  return 1;
}
