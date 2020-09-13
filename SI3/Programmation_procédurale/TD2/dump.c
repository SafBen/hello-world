#include <stdio.h>

int main(){
	int c;
	int i=0;
	int str[16];
	while ((c=getchar()) != EOF){
		str[i%16]=c;
		printf("%02x ", c);
		if (i%16==15){
			printf("  |");
			for (int j=0;j<16;j++){
				if (str[j]>=' ' && str[j]<'~'){
					printf("%c", str[j]);
				}
				else printf(".");
			}
			printf("|\n");
		}
		i++;
	}
	for (int j=i%16;j<16;j++) printf("   ");
	printf("  |");
	for (int j=0;j<i%16;j++){
		if (str[j]>=' ' && str[j]<'~'){
					printf("%c", str[j]);
				}
				else printf(".");
			}
	printf("|");
	printf("\n");
	return 0;
}