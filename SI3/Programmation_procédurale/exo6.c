#include <stdio.h>
/*
int est_dans_tableau(int n,tab [n], char c){
	for (int i=0;i<=n,i++){
		if (c==tab[i]) return i;
		else return -1;
	}
}

printf("%c\n",c);
		dans_tab=0;
		for (int j=0;j<=10;j++){
			printf("%d\n", j);
			if (c==tab[j][0]){
				dans_tab=1;
				indice = j;
				printf("%d\n", j);
			}
		}
		printf("ok");
		if (dans_tab){
			tab[indice][1]++;
		}
		else{
			tab[indice+1][0]=c;
		}
*/
int main(){
	int tab1[200] = {0};
	int tab2[200] = {0};
	char c;
	int i=0;
	while ((c=getchar()) != EOF){
		tab2[c]++;
		tab1[c]=c;
	}
	for (int j=0;j<=150;j++){
		printf("%c: %d fois\n",tab1[j],tab2[j]);
	}
	return 0;
}