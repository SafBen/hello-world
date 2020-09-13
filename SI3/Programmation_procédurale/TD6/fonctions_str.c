#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *Strcpy(char *dest, const char *src){
	//char *sauv=dest;
	while(*dest++=*src++);
	return dest;
}

size_t Strlen(const char *s){
	size_t taille=0;
	while(*s++) taille++;
	return taille;
}

char* Strdup(const char *s){
	char *str=malloc(sizeof(char));
	strcpy(str,s);
	return str;
}

char *Strchr(const char *s, int c){
	while (*s){
		if (*s==c) return s;
		s++;
	}
	return NULL;
}


int main(int argc, char const *argv[])
{
	
	char *dest = (char *) malloc(40*sizeof(char));
	char *src = "bonjour";
	

	char txt[10]="abcjour";
	char txtcpy[10];
	Strcpy(txtcpy,txt);
	Strcpy(dest,src);
	printf("%s\n", txtcpy);
	printf("%s\n", dest);
	printf("%ld\n", Strlen(dest));
	char* str=Strdup(src);
	printf("%s\n", str);
	free(dest);
    
    return 0;
}