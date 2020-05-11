#include <stdio.h>
#include <ctype.h>

int main()  {
	int i=0,j=0,k=0;
	while(i<10){
		k=j+++i++;
	}
	// des MOTS en minuscules ET EN MAJUSCULES
	printf("i=%d j=%d k=%d\n",i,j,k);
	printf("%c",toupper('a'));
	printf("%d\n",' ');
	return 0;
}
