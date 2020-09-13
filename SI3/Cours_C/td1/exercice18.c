#include <stdlib.h>
#include <stdio.h>

int main() {
  int a = 2, b = 3, c = 4, d = 5, e = 6, f = 7;
  int res1,res2,res3;
  res1 = a*a-c+a/(b*c+c/(d+e/f));
  res2 = (-b+b*b-4*a*c)/(2*a);
  res3 = (1/a+1/b)/(c+d);
  printf("res1 = %d\nres2 = %d\nres3 = %d\n",res1,res2,res3);
}
