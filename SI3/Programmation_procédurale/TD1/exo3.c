#include <stdio.h>

int main(){
	int x;
	int max=0;
	int somme=0;
	int i=0;
	while (scanf("%d",&x) && x>0){
		i++;
		if (max<x) max=x;
		somme+=x;
	}
	printf("Nombre d'entiers saisie = %d\nMax = %d\nSomme = %d\n",i,max,somme);
	return 0;
}