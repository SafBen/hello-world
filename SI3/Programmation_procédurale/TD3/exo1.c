#include <stdio.h>
#include <string.h>

int indice(const char str[], const char c){
	int i=0;
	while (str[i]!='\0'){
		if (str[i]==c) return i;
		i++;
	}
	// c n'est pas dans la chaîne str
	return -1;
}

int indice_droite(const char str[], const char c){
	int i=0;
	while (str[i]!='\0'){
		if (str[strlen(str)-1-i]==c) return strlen(str)-1-i;
		i++;
	}
	// c n'est pas dans la chaîne str
	return -1;
}

int main(){
	char str[10]="Test";
	printf("%s\n", str);
	//printf("%ld\n", strlen(str));
	printf("%d\n", indice(str,'T'));
	printf("%d\n", indice(str,'t'));
	printf("%d\n", indice(str,'z'));
	printf("%d\n", indice("Tester",'e'));
	printf("%d\n", indice_droite(str,'T'));
	printf("%d\n", indice_droite(str,'t'));
	printf("%d\n", indice_droite(str,'z'));
	printf("%d\n", indice_droite("Tester",'e'));
	return 0;
}