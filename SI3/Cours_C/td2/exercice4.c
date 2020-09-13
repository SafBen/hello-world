#include <stdlib.h>
#include <stdio.h>

int main(void) {
  enum booleen {FAUX, VRAI};
  enum booleen a;
  enum booleen b;
  //type : en c on peut faire des types mais restrictions : idetificateur de constante entière//
  a = VRAI;
  b = FAUX;
  printf("a = %d\nb = %d\n", a,b);
  return EXIT_SUCCESS;
}
