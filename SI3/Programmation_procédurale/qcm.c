#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
void strrev(char str[]){
	int n=strlen(str);
	char tmp;
	char res[100];
	for (int i=0;i<n;i++){
		res[i]=str[n-1-i];
	}
	for (int i=0;i<n;i++){
		str[i]=res[i];
	}
}
*/

void initialiser(int tab[10][10],int val){
	int *p=tab[0];
	for (int i=0;i<100;i++) *p++=val;
}

void decale(char str[]){
	for (int i=0;i<strlen(str);i++) str[i]++;
}

int main(int argc, char *argv[]){
	char str[]="Hello";
	decale(str);
	printf("%s\n", str);
}