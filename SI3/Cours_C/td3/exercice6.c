#include <stdlib.h>
#include <stdio.h>

float x,a,b;

int main () {
  scanf("%f %f",&a,&b);
  if (a==0 && b==0)
    printf("Tout x est solution\n");
  else
    if (a==0 && b!=0)
      printf("Pas de solution\n");
  if (a!=0)
    printf("%f\n",-b/a);
  return EXIT_SUCCESS;
}
