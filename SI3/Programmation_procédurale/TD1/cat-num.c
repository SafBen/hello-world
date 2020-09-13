#include <stdio.h>

int main(){
	int c, fin = '\n';
	int lignes=1;
	while ((c=getchar())!=EOF){
		if (fin=='\n'){
			printf("%d ",lignes);
			lignes++;
		}
		putchar(c);
		fin = c;
	}
	return 0;
}