#include <stdio.h>

#define CHAR_SIZE  8                        /* nombre de bits dans un char */
#define MAX_BIGSET 125                      /* nombre de cellules dans un ensemble */
#define MAX_VAL    (CHAR_SIZE * MAX_BIGSET)

typedef unsigned char BigSet[MAX_BIGSET];   /* un ensemble dans [0 .. MAX_VAL[  */

void imprimer(int n,int base){
	if (n<0){
		putchar('-');
		n=-n;
	}
	if (n>=base){
		imprimer(n/base,base);
	}
	putchar(n%base+((n%base)>9?'A'-10:'0'));
}

void en_binaire(int n){
	unsigned int masque = 1<<(8*sizeof(unsigned int)-1);
	while (masque){
		putchar(((masque&n)==0) ? '0' : '1' );
		masque>>=1;
	}
	putchar('\n');
}

void BigSet_init(BigSet s){
	for (int i = 0; i < MAX_BIGSET; i++)
	{
		s[i]=0;
	}
}

void BigSet_add(BigSet s, int i){
	int indice = i/CHAR_SIZE;
	int numero = i%CHAR_SIZE;
	s[indice] |= 1<<numero;
}

int BigSet_is_in(BigSet s, int i){
	int indice = i/CHAR_SIZE;
	int numero = i%CHAR_SIZE;
	return (s[indice] & 1<<numero) != 0;
}

void BigSet_print(BigSet s){

	putchar('{');
	for (int i = 0; i < MAX_BIGSET; i++)
	{
		for (int j = 0; j < CHAR_SIZE; j++)
		{
			if (s[i] & (1<<j))
			{
				printf("%d, ", i*8+j);
			}
		}
	}
	printf("}\n");
}

void BigSet_inter(BigSet s1, BigSet s2, BigSet res){
	BigSet_init(res);
	for (int i = 0; i < MAX_BIGSET; i++)
    	res[i] = s1[i] & s2[i];
}

void insertion(int array[], int nbval, int n)
{
  int i, j;
  printf("%d\n", nbval);

  // Trouver la position j où doit se faire l'insertion
  for (j = 0; j < nbval; j++) {
    if (array[j] > n) break;  // break sort de la boucle
  }

  // décaler les éléments à droite de j de 1 case vers la droite
  for (i = nbval; i > j; i--) {
    array[i] = array[i-1];
  }

  // Mettre n dans array[j]
  array[j] = n;
}

void print_array(int array[], int nbval){
  int i;

  printf("[ ");
  for (i = 0; i < nbval; i++)
    printf("%d ", array[i]);
  printf("]\n");
}

int main2(int argc, char const *argv[])
{
	BigSet e1, e2, e3;

	BigSet_init(e1); BigSet_init(e2);

	for (int i = 0; i < 140; i += 12) BigSet_add(e2, i);
	for (int i = 0; i < 140; i += 9) BigSet_add(e1, i);

	BigSet_inter(e1, e2, e3);

	printf("e1 = "); BigSet_print(e1);
	printf("e2 = "); BigSet_print(e2);
	printf("e3 = "); BigSet_print(e3);

	printf("%d\n", BigSet_is_in(e2,1));
	
	return 0;
}

int main(void)
{
  int array[100];
  int n, items, nbval = 0;

  do {
    printf("Entrer un entier: ");
    items = scanf("%d", &n);
    if (items == 1 && n >= 0) {
      /* le nombre saisi est positif */
      insertion(array, nbval++, n);
      print_array(array, nbval);
    }
  } while (items == 1  && n >= 0);
}