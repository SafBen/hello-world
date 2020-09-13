#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void cat_strings(char *str1, ...){
	char *s;
	char *dest=malloc(strlen(str1)*sizeof(char));
	dest=strcat(dest,str1);
	va_list va;
	va_start(va,str1);
	s=va_arg(va,char *);
	while(s){
		dest=realloc(dest,strlen(s)*sizeof(char));
		dest=strcat(dest,s);
		s=va_arg(va,char *);
	}
	va_end(va);
	printf("%s\n", dest);
	free(dest);
}

int main(){
	cat_strings("es","sai"," et bonjour tout le monde",NULL);
	return 0;
}