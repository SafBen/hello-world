#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

// CHERCHER COMMENT DETERMINER Nmax

int factorielleDecroissant(int n) {
  int i,fact;
  i = n;
  fact = 1; // = 1 sinon ne vérifie pas n!/n!
  //invariant de boucle fact = n!/i!
  while (i!=0) { // différent de 1 car si i = 0 le résultat sera toujours 0
    //{fact=n!/i!} mais on doit faire apparaître i-1 donc fact*(i-1)=n!/(i-1)!
    fact = fact*i;
    //{fact = n!/(i-1)!}
    i=i-1;
  //{fact=n!/i! et i = 0} conséquent
  }
  return fact;
}

int main(void){
  int n;
  scanf("\n%d",&n);
  printf("%d\n",factorielleDecroissant(n));
  printf("%d\n",INT_MAX);
}

//
