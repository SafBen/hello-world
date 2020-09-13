#include <stdlib.h>
#include <stdio.h>

double x,y,z;

int main () {
  scanf("%lf %lf %lf",&x,&y,&z);
  //
  if (x<y) {
    if (y<z)
      printf("%lf %lf %lf",x,y,z);
    else
      if (x<z)
        printf("%lf %lf %lf",x,z,y);
      else
	printf("%lf %lf %lf",z,x,y);
  else
    if (x<z)
      printf("%lf %lf %lf",y,z,x);
