#include <stdio.h>
#include <string.h>

void suppress_char(char str[], char c){
	for (int i=0;i<strlen(str);i++){
		if (str[i]==c){
			for (int j=i;j<strlen(str);j++)
				str[j]=str[j+1];
			i--;
		}
	}
}

int main(){
	char s[]="ooooabonjourooo";
	suppress_char(s,'o');
	printf("%s\n", s);
}