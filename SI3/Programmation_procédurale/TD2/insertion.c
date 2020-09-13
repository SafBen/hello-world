#include <stdio.h>

void insertion(int tab[],int taille,int v){
	int i=0;
	while (v>=tab[i]){
		i++;
	}
	for (int j=taille;j>i;j--){
		tab[j]=tab[j-1];
	}
	tab[i]=v;
	
}

int main(){
	int taille=1;
	int tab[20]={0};
	tab[0]=5;
	for (int i=0;i<=5;i++){
		taille++;
		insertion(tab,taille,2*i+6);
	}
	for (int j=0;j<taille;j++){
		printf("tab[%d]=%d\n",j, tab[j]);
	}
}