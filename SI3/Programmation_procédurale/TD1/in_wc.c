#include <stdio.h>

int main(){
	int c, NbChar=0,NbLine=0,NbWord=0;
	while ((c=getchar()) != EOF){
		NbChar++;
		if (c=='\n') {
			NbLine++;
			NbWord++;
		}
		if (c==' ' | c=='\t') NbWord++;
	}
	printf("char = %d\nligne = %d\n mot = %d\n",NbChar,NbLine,NbWord);
	return 0;
}