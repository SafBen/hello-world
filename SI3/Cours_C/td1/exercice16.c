#include <stdlib.h>
#include <stdio.h>

int main() {
  int x=2,y=5;
  y += (x += 1) + 3;
  int b1=1,b2=3,b3=7;
  b1 &= (b2 += b1==b3 + 1);
  printf("y = %d\nb1 = %d  b2 = %d  b3 = %d\n",y,b1,b2,b3);
}
