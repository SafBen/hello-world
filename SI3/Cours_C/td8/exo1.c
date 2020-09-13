#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void identite(int n, int mat[][n]){
  for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<n ; j++){
	mat[i][j]=0;
    }
    mat[i][i]=1;
  }
}

void ecrireMatrice(int n, int mat[][n]){
  for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<n-1 ; j++){
      printf("%d  ",mat[i][j]);
    }
    printf("%d\n",mat[i][n-1]);
  }
}

void initAleatoire(int n, int mat[][n]){
  for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<n ; j++){
      mat[i][j] = rand()%100;
    }
  }
}

int main(void){
  int n;
  scanf("%d", &n);
  assert (n>0);
  int mat[n][n];
  identite(n,mat);
  // initAleatoire(n,mat);
  ecrireMatrice(n,mat);
  return EXIT_SUCCESS;
}
  
