#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int y;
  scanf("%*d %% %d %% %*d",&y); //% c'est un spécificateur de conversion//
  //* permet de remplacer des variables inutilisées//
  printf("%d\n", y);
  return EXIT_SUCCESS;
}
