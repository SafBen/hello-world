#include <stdlib.h>
#include <stdio.h>

int main () {
  int x = 033;
  int y = 2;
  int z1 = x & y;
  int z2 = x && y;
  int z3 = x | 02;
  int z4 = 02 == 0x2;
  int z5 = 0xff & 0x0;
  int z6 = 2.0 == 2.0;
  int z7 = 6 ^ 3;
  int z8 = ~0xffffffff;
  printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",z1,z2,z3,z4,z5,z6,z7,z8);
}
