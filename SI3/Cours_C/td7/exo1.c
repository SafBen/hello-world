#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* antécédent : n>0
 * conséquent : renvoie la somme 1 + 1/2 + 1/3 +...+ 1/n 
 */

double somme(int n) {
  double sum = 0;
  assert (n>0);
  for (int i = 1; i <= n; i++) //  ça marche pas car division entière ATTENTION on ne met pas double i à cause de l'énocncé
    sum += 1.0/i; // on force l'entier 1 à un float 1.0
  return sum;
}

int main(){
  int n;
  scanf("%d",&n);
  printf("somme = %f\n",somme(n));
  return EXIT_SUCCESS;
}
