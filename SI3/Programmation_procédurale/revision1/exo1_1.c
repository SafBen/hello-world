#include <stdio.h>

void insertion2(int tab[], int size, int val){
	int i=size;
	while (val<tab[i-1] && i>0){
		tab[i]=tab[i-1];
		i--;
	}
	tab[i]=val;
}

void insertion(int array[], int nbval, int n)
{
  int j;

  for (j = nbval; (j > 0) && (array[j-1] > n); j--) { // Décalage des éléments > à n
    array[j] = array[j-1];
  }
  array[j] = n;                                        // Insertion
}

void print_array(int array[], int nbval){
  int i;

  printf("[ ");
  for (i = 0; i < nbval; i++)
    printf("%d ", array[i]);
  printf("]\n");
}

int main() {
	int x;
	int tab[10]={};
	int n=0;
	for (int i=0;i<5;i++){
		printf("Entrer un entier : ");
		scanf("%d",&x);
		insertion2(tab,n++,x);
		print_array(tab,n);
	}
	return 0;
}