#include <stdio.h>
#include <stdlib.h>

int main (){
	int c,cfin='\n';
	int numlignes=1;
	while((c=getchar())!=EOF){
		if(cfin=='\n'){
			printf("%d",numlignes);
			numlignes++;
		}
		putchar(c);
		cfin=c;
	}
	return 0;
}
