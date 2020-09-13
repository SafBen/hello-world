#include <stdio.h>
#include <string.h>

int indice(const char str[], const char c){
	for (int i=0;i<strlen(str);i++){
		if (str[i]==c) return i;
	}
	return -1;
}

int indice_droite(const char str[], const char c){
	for (int i=strlen(str)-1;i>=0;i--){
		if (str[i]==c) return i;
	}
	return -1;
}

int palindrome(const char str[]){
	int n=strlen(str);
	for (int i=0;i<n/2;i++){
		if (str[n-i-1]!=str[i]) return 0;
	}
	return 1;
}

void suppress_char(char str[],char c){
	int j;
	for (int i=0;str[i]!='\0';i++){
		if (str[i]==c){
			for (j=i+1;str[j]!='\0';j++){
				str[j-1]=str[j];
			}
		}
	}
	str[j]='\0';
}

int main() {
	char str[]="bonjouro";
	printf("%s\n", str);
	suppress_char(str,'o');
	printf("%s\n", str);
	return 0;
}