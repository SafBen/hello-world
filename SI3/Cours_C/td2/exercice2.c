#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
  double x;
  scanf("%lf", &x); //spécification f = float et l c'est pour une spécification de conversion pour un entier long pas un float erreur sujet//
  printf("%lf\n", floor(x));
  printf("%.0lf\n", floor(x)); //%.0 => 0 chiffres après la virgule
  return EXIT_SUCCESS;
}
