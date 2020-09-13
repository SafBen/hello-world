#include <stdio.h>

int main(){
	int x;
	int i=0;
	while (scanf("%d",&x) && x>0){
		i++;
	}
	printf("Nombre d'entiers saisie = %d\n",i);
	return 0;
}