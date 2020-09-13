#include <stdlib.h>
#include <stdio.h>

int main() {
  int x = 1,y = 2;
  int res1,res2,res3,res4;
  res1 = 2+3*4+12%3;
  res2 = 3<<4+23-2==5!4;
  res3 = 1!=(x++==--y);
  res4 = ~4+22~3&&6;
  printf("res1 = %d\nres2 = %d\nres3 = %d\nres4 = %d\n",res1,res2,res3,res4);
}
