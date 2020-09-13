#include <stdio.h>
#include <string.h>

void decale(char s[], int dec, int pos){
	for (int i=pos;i<pos+strlen(s);i++){
		s[i]=s[i+1];
	}
}

int Strstr(char a[], char b[]){
	int j;
	for (int i=0;i<strlen(a);i++){
		j=0;
		while (a[i+j]==b[j++]){
			if (j==strlen(b)) return i;
		}
	}
	return 0;
}

void suppression(char str[], char suppr[]){
	while (Strstr(str,suppr)){
		decale(str, strlen(suppr), Strstr(str,suppr));
	}
}

int main(int argc, char *argv[]){
	char str[]="Bonjour";
	char suppr[]="on";
	suppression(str,suppr);
	printf("%s\n", str);
}