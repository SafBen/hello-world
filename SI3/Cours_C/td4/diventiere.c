#include <stdlib.h>
#include <stdio.h>

int divisionEntier(int a, int b) {
  int r,q;
  r = a;
  q = 0
  while (b <= r) {
    r = r-b;
    q++;
  }
  return q,r;
}

int main(void) {
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d %d\n",divisionEntier);
}
