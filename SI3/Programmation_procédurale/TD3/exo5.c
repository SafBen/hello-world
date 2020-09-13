#include <stdio.h>
#include <string.h>

int Strstr(char a[], char b[]){
	int j;
	for (int i=0;i<strlen(a);i++){
		j=0;
		while (a[i+j]==b[j++]){
			if (j==strlen(b)) return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]){
	char a[111]={0};
	int i=0;
	int ligne=0;
	while ((a[i++]=getchar())!=EOF) {
		printf("%s\n", a);
		if (a[i]=='\n') ligne++;
		if (Strstr(a,argv[1])){
			printf("chaine trouvée à la ligne %d\n",ligne);
		}
	}
}