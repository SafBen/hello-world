#include <stdio.h>
#include <stdarg.h>


void imprime(char text[],...){
	va_list ap;
	va_start(ap,text);
	while (text){
		printf("%s ", text);
		printf("%d ", va_arg(ap,int));
		text=va_arg(ap,char*);
	}
}

int main(int argc, char const *argv[])
{
	int x=1,y=2;
	imprime("Valeur de x= ",x," Valeur de y= ",y," => x+y= ",x+y,NULL);
	return 0;
}