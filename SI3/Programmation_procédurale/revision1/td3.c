#include <stdio.h>
#include <string.h>

int indice(const char str[], const char c){
	int i=0;
	while(str[i]!=c) i++;
	return (i>=strlen(str)) ? -1 : i;
}

int indice_droite(const char str[], const char c){
	int i=strlen(str);
	while(str[--i]!=c);
	return (i<0) ? -1 : i;
}

int palindrome(const char str[]){
	int i=0,j=strlen(str)-1;
	while(str[i++]==str[j--]);
	return (j>=0) ? 0 : 1;
}

void Strcpy(char s1[], char s2[]){
	int i=0;
	while(s2[i]){
		s1[i]=s2[i];
		i++;
	}
}

int  Strcmp(char s1[], char s2[]){
	int i=0;
	while(s1[i]==s2[i] && s1[i] && s2[i]) i++;
	if (s1[i]==s2[i]){
		return 0;
	}
	else return (s1[i]<s2[i]) ? -1 : 1;
}

void strupper(char s[]){
	int i=0;
	while(s[i]){
		if (s[i]<='z' && s[i]>='a') s[i]=s[i]-'a'+'A';
		i++;
	}
}

void suppress_char(char str[], char c){
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]==c)
		{
			for (int j = i; j < strlen(str); j++)
			{
				str[j]=str[j+1];
			}
		}
	}
}


int main(int argc, char const *argv[]){
	
	printf("%d\n", indice("Test",'T'));
	printf("%d\n", indice("Test",'t'));
	printf("%d\n", indice("Test",'z'));
	printf("%d\n\n", indice("Tester",'e'));

	printf("%d\n", indice_droite("Test",'T'));
	printf("%d\n", indice_droite("Test",'t'));
	printf("%d\n", indice_droite("Test",'z'));
	printf("%d\n\n", indice_droite("Tester",'e'));

	printf("%d\n", palindrome("ressasser"));
	printf("%d\n", palindrome("kayak"));
	printf("%d\n", palindrome("X"));
	printf("%d\n", palindrome("test"));
	printf("%d\n", palindrome("abccba"));

	char s1[]="bonjour";
	char s2[]="nonaurevoir";
	Strcpy(s1,s2);
	printf("%s\n", s1);

	printf("%d\n", Strcmp("abc","z"));
	printf("%d\n", Strcmp("abc","abd"));
	printf("%d\n", Strcmp("trié","triée"));

	char str[]="bonJouR";
	strupper(str);
	printf("%s\n", str);
	
	char string[] = "bonjour";
	suppress_char(string,'o');
	printf("%s\n", string);

	char string2[] = "bonjour comment ça va";
	suppress_char(string2,'c');
	printf("%s\n", string2);

	char string3[] = "moi je m'appelle safwane";
	suppress_char(string3,'e');
	printf("%s\n", string3);

	char string4[] = "bonjour";
	suppress_char(string4,'b');
	printf("%s\n", string4);
	
	
	return 0;
}