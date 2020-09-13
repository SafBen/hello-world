#include <stdio.h>

int main(int argc, char const *argv[]){
	char c;
	char ligne[16];
	int i,compteur=0;
	while((c=getchar())!=EOF){
		if (compteur==16)
		{
			compteur=0;
			for (i = 0; i < 16; i++)
			{
				printf("%02x ",(unsigned char) ligne[i]);
			}
			printf("  | ");
			for (i = 0; i < 16; i++)
			{
				printf("%c", (' ' <= ligne[i] && ligne[i] < '~') ? ligne[i]: '.');
			}
			printf("\n");
		}
		ligne[compteur++]=c;
	}
	return 0;
}