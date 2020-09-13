#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1E-300

int main (void){
  long double a,b,c,delta ;
  long double r1,r2,i1,i2 ;
  scanf("%Lf %Lf %Lf",&a,&b,&c);
  assert(fabsl(a)>=EPSILON);
  delta = b*b-4*a*c;
  if (delta >= 0) {
    /* calcul des racines réelles :
     * on calcule d'abord la racine qui a la valeur absolue la plus grande*/
    r1 = (b>0 ? -(b+sqrtl(delta)) : (-b+sqrtl(delta))) / (2*a) ;
    /* r1 racine la + grande en valeur absolue */
    /* calculer r2 par le produit*/
    r2 = (fabsl(r1)<EPSILON) ? 0 : c/(a*r1);
    i1 = i2 = 0;
    printf("%Lf %Lf\n",r1,r2);
  }
  else {
    /* calcul des racines complexes */
    r1 = r2 = -b/(2*a);
    i1 = sqrtl(-delta)/(2*a);
    i2 = -i1;
  }
}
