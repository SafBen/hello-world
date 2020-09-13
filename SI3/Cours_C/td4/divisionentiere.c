#include <stdlib.h>
#include <stdio.h>

int quotient(int a, int b) {
  int r,q;
  // invariant de boucle a = bq+r
  r = a;
  q = 0;
  // a = 0*b + a
  while (b <= r) {
    r = r-b;
    q++;
  }
  return q;
}

int reste(int a, int b) {
  int r;
  r = a - quotient(a,b)*b;
  return r;
}


int main(void) {
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d %d\n",quotient(a,b),reste(a,b));
}

int produit(int x, int y) {
  int a,p;
  a = x;
  p = 0;
  // xy = ab + p
  while (b & 1 == 0) {  // (x&1)==1 impair si = 0 pair
    b /= 2;
    a *= 2;
  }
  while (b > 0) {
    b++;
    p += a;
    
