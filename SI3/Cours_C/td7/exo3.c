#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define N 10

int initTab(int t[], int n){
  for (int i = 0; i<n ; i++)
    t[i] = rand()%100;
  for (int i = 0; i<n ; i++)
    printf("%d\n",t[i]);
}

int main(){
  int t[N];
  initTab(t[N],N);
  return EXIT_SUCCESS;
}
