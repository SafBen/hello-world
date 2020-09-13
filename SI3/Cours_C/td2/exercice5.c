#include <stdlib.h>
#include <stdio.h>

int main(void) {
  enum booleen {FAUX, VRAI};
  enum couleur {BLEU = 10, JAUNE=-29, ROUGE= -30, VERT};
  printf("FAUX = %d\nVRAI = %d\n", FAUX, VRAI);
  printf("FAUX = %d\n",FAUX + 5);
  printf("VERT = %d\n", VERT);
  printf("JAUNE = %d\n", JAUNE);
  return EXIT_SUCCESS;
}
