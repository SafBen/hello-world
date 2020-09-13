#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(int a, int b){
  for (int i=a ; i<=b ; i++)
    printf("%f ",pow(i,3)/2);
  return EXIT_SUCCESS;
}
