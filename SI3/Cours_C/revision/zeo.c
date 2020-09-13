#include <stdlib.h>
#include <stdio.h>


#define NB_BITS (sizeof(unsigned  int))

unsigned  int valeurDecimale(const short bits []) {
  unsigned  int n = 0;
  for (int i=NB_BITS -1; i>=0; i--)
    n = (n<<1) + bits[i];//
  return n;
}

int main(){
  short bits [NB_BITS];
  for (int i = 0; i<NB_BITS ; i++)
    bits[i] = rand()%2;
  bits[0]=0;
  bits[1]=1;
  bits[2]=1;
  bits[3]=0;
  for (int i = 0; i<NB_BITS ; i++)
    printf("%d ",bits[i]);
  printf("\n%d\n",valeurDecimale(bits));
}
