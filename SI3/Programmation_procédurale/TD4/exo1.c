#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_iteratif_base10(int x){
	int tab[20];
	int i=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while (x){
		tab[i++]=x%10;
		x/=10;
	}
	for (--i;i>=0;i--)
		putchar('0'+tab[i]);
	putchar('\n');
}

void print_recursif_base10(int n) {
	if(n<0){
		putchar('-');
		n=-n;
	}
	if (n >= 10) print_recursif_base10(n / 10);
	putchar('0' + n%10);
}

void print_iteratif_base_b(int x,int base){
	int tab[20];
	int i=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while (x){
		tab[i++]=x%base;
		x/=base;
	}
	for (--i;i>=0;i--)
		putchar('0'+tab[i]);
	putchar('\n');
}

void print_recursif_base_b(int n,int base) {
	if(n<0){
		putchar('-');
		n=-n;
	}
	if (n >= base) print_recursif_base_b(n / base,base);
	putchar('0' + n%base);
}

void en_binaire_rec(int n){
	if (n>=2) en_binaire_rec(n>>1);
	putchar((n&1)?'1':'0');
}

void en_binaire(int n){
	unsigned masque = 1 << (sizeof(unsigned int)*8-1);
	while (masque>0){
		putchar((masque&n)?'1':'0');
		masque>>=1;
	}
	putchar('\n');
}
/*
int* palindromeNombre(int taille){
	int tab[100];
	int indice=0;
	char chiffre[taille];
	for (int i = 1000; i < 3000; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			chiffre[j]='0'+i/10;
		}
		if (nombreEstUnPalindrome(chiffre)){
			tab[indice++]=i;
		}
	}
	return tab;
}
*/

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int nombreEstUnPalindrome(char chiffre[]){
	int n = strlen(chiffre);
	//char *s=chiffre;
	int endroit=atoi(chiffre);
	strrev(chiffre);
	int envers=atoi(chiffre);

	if (envers==4*endroit || endroit==4*envers) return 1;
	else return 0;
}



int main(int argc, char *argv[]){
	/*
	int x = -67354;
	print_recursif_base10(x);
	putchar('\n');
	print_iteratif_base10(x);
	int n = 15;
	print_recursif_base_b(n,2);
	putchar('\n');
	print_iteratif_base_b(n,2);
	*/
	//en_binaire(323753);


	int tab[10]={};
	int indice=0;
	int taille = 3;
	char chiffre[taille];
	char *chiffre_rev;
	int x=0;
	for (int i = 1000; i < 10000; i++)
	{
		x=i;
		for (int j = 0; j < taille; j++)
		{
			chiffre[j]='0'+x%10;
			x/=10;
		}
		chiffre[taille]='\0';
		chiffre_rev=strrev(chiffre);
		if (atoi(chiffre)==4*atoi(chiffre_rev)
			|| 4*atoi(chiffre)==atoi(chiffre_rev)){
			tab[indice++]=i;
		}
	}
	for (int k = 0; k < 3; k++)
	{
		printf("%d\n", tab[k]);
	}
	
}