#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPSILON 1E-300

int main (void){
  double a,b,c,delta,r1,r2;
  scanf("%lf %lf %lf",&a,&b,&c);
  assert(fabs(a)>=EPSILON);
  delta = b*b-4*a*c;
  if (delta >= 0)
    /* calcul des racines réelles */
    r1 = (-b-sqrt(delta))/(2*a);
    r2 = (-b+sqrt(delta))/(2*a);
    printf("%f %f",&r1,&r2);
    i1=i2=0;
}
    