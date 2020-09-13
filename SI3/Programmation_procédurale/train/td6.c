#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char *Strchr(const char *s, int c){
	for (;*s;s++)
		if (*s==c) return (char *) s;
	return NULL;
}

char *Strcpy2(char *dest, const char *src){
	while(*src){
		*dest++=*src;
		src++;
	}
	return dest;
}

char *Strcpy(char *s1, const char *s2) {
  char *sauvegarde = s1;

  while ((*s1++ = *s2++)) { /* Rien */ }
  return sauvegarde;
}

int Strlen(const char *s){
	const char *cpy=s;
	while (*++s);
	return s-cpy;
}

char *Strdup(const char *s) {
  char *new = malloc(Strlen(s) + 1);  /* ne pas oublier le + 1 pour le '\0' */

  return Strcpy(new, s);
}

float moyenne(int count,...){
	va_list va;
	float sum=0;
	va_start(va,count);
	for (int i = 0; i < count; i++)
	{
		sum+=(float) va_arg(va,double);
	}
	return sum/count;
}

int main(int argc, char const *argv[])
{
	char *str = "bonjour";
	char *dest;
	int c = 'j';
	char *s = Strdup(str);
	printf("%s\n", s);
	printf("%d\n", Strlen(str));
	printf("Moyenne1 = %f\n", moyenne(2, 10.0, 15.0));
	return 0;
}