#include <stdio.h>
#include <stdlib.h>

void trianglePascal(int n,int tp[n+1][n+1]){
  tp[0][0]=1;
  for(int i=1;i<=n;i++){
    
    tp[i][0]=tp[i][i]=1;
    for(int j=1;j<i;j++){
	
	tp[i][j]=tp[i-1][j]+tp[i-1][j-1];
      }
  }
  
}

void afficher(int n,int tp[n+1][n+1]){
for(int i=0;i<=n;i++){
	for(int j=0;j<i;j++){
	printf("%d  ",tp[i][j]);
	}printf("%d\n",tp[i][i]);
   } 
}
int main(void){

  int n;
  scanf("%d",&n);
  int tp[n+1][n+1];
 
  trianglePascal(n,tp);
  afficher(n,tp);
return 0;
}
