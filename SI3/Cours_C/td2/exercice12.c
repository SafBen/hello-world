#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

int main(void) {
  double temps;
  int min, heure, seconde, centieme;
  scanf("%lf", &temps);
  assert(temps>=0);
  seconde = floor(temps);
  centieme = (temps - seconde)*100;
  min = seconde/60;
  heure = min/60;
  seconde = seconde - 3600* heure - 60*min;
  printf("temps = %dh %dmin %dseconde et %dcentieme\n",heure,min,seconde,centieme);  
  return EXIT_SUCCESS;
}
