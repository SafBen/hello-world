#include <stdlib.h>
#include <stdio.h>

int x;

int main () {
  scanf("%d",&x);
  if (x<0)
     printf("x est négatif\n");
  else
    if (x==0) {
        printf("x est nul\n");
    }
    else
        printf("x est positif\n");
  
  if (x%2==0)
    printf("x est pair\n");
  else
    printf("x est impair\n");
  return EXIT_SUCCESS;
}
