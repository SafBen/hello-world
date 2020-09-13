#include <stdio.h>


int main() {
  char lettres[26]={};
  char chiffres[10]={};
  char c;
  while((c=getchar())!=EOF){
  	if (c>='0' && c<='9') chiffres[c-'0']++;
  	if (c>='a' && c<='z') lettres[c-'a']++;
  }
  for (int i = 0; i < 10; i++)
  {
  	if (chiffres[i]!=0) printf("%c: %d fois\n", '0'+i,chiffres[i]);
  }
  for (int i = 0; i < 26; i++)
  {
  	if (lettres[i]!=0) printf("%c: %d fois\n", 'a'+i,lettres[i]);
  }
  return 0;
}

/*
cat-num exercice 4 feuille 1

char c;
	int nbLignes=1;
	putchar('0'+1);
	putchar(' ');
	while((c=getchar())!=EOF){
		putchar(c);
		if (c=='\n'){
			putchar('0'+ (++nbLignes));
			putchar(' ');
		}
	}
	putchar('\n');
*/