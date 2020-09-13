#include <stdio.h>

int isin(const char *s,char c){
	while (*s){
		if (*s++==c){
			return 1;
		}
	}
	return 0;
}

int Strspn(const char s[], const char accept[]){
	int compteur=0,i=0,j=0;
	while (s[i]){
		if (!(isin(accept,s[i]))) return compteur;
		j=0;
		while (accept[j]){
			if (accept[j]==s[i]) compteur++;
			j++;
		}
		i++;
	}
	return compteur;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", Strspn("essai","esai"));
	printf("%d\n", Strspn("essai","se"));
	printf("%d\n", Strspn("essai","asze"));
	printf("%d\n", Strspn("essai","ei"));
	printf("%d\n", Strspn("essai","xyz"));
	return 0;
}