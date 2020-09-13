#include <stdlib.h>
#include <stdio.h>

#define epsilon 1e-3

float f(float x){
  return x-5;
}

float zero(float a, float b, int max){ // max est le nombre maximal d'itérations
  float m=(a+b)/2;//m est le milieu de [a,b]
  int i=0;
  //
  while ( f(m) > epsilon || i<max){
    if (f(m) == 0) return m;
    if (f(a)*f(m)<0){
      b=m;//on se place dans l'intervalle [a,m]
      m=(a+b)/2;
      i++;
    }
    if (f(b)*f(m)<0){
      a=m;//on se place dans l'intervalle [m,b]
      m=(a+b)/2;
      i++;
    }
  }
  return m;
}
    
int main(){
  float m = zero(0,10,1000);
  printf("zero=%f\nf(zero)=%f\n",m,f(m));
  return EXIT_SUCCESS;
}
