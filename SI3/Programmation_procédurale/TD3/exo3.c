#include <stdio.h>
#include <string.h>

void Strcpy(char s1[], char s2[]){
	for (int i=0;i<strlen(s2);i++){
		s1[i]=s2[i];
	}
}

int Strcmp(char s1[], char s2[]){
	int i=0;
	while (s1[i]==s2[i]) i++;
	if (i>strlen(s1)) i--;
	if (i==strlen(s1)) return 0;
	else if (s1[i]<s2[i]) return -1;
	else return 1;
}

void Strupper(char s[]){
	for (int i=0;i<strlen(s);i++){
		if (s[i]>='a' && s[i]<='z') s[i]=s[i]-'a'+'A';
	}
}

int main(){
	char s1[]="aBcd";
	char s2[]="abcc";
	Strupper(s1);
	printf("%s\n", s1);
	return 0;
}