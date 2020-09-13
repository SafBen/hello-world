#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

long factorielle(int n){
  long fact = 1;
  for (int i=2 ; i<=n ; i++)
    fact=fact*i;
  return fact;
}


int main(void){
  int n=2;
  long factn=1;
  while ( factn < LONG_MAX/n){
    n++;
    factn=factorielle(n);
    printf("factn=%ld\n",factn);
  }
  printf("n=%d\n LONG_MAX=%ld",n,LONG_MAX);
  return EXIT_SUCCESS;
}
/*

int main(void) {
  int n=2;
  long fact_n_1 = 1;
  while (n<=( LONG_MAX/fact_n_1 ))
    fact_n_1 = factorielle (++n);
  printf("n=%d\n", n);
  return EXIT_SUCCESS;
}
*/
