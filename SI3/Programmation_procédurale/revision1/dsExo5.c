#include <stdio.h>
#include <string.h>

int palindrome_sans_espace(char s[]){
	for (int i=0,j=strlen(s)-1;i<j;i++,j--){
		if (s[i]!=s[j]) return 0;
	}
	return 1;
}

int palindrome_avec_espace(char s[]){
	for (int i=0,j=strlen(s)-1;i<j;i++,j--){
		if (s[i]==' ') i++;
		if (s[j]==' ') j--;
		if (s[i]!=s[j]) return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", palindrome_sans_espace("kayak"));
	printf("%d\n", palindrome_sans_espace("abccba"));
	printf("%d\n", palindrome_sans_espace("kayAk"));
	printf("%d\n", palindrome_sans_espace("kayaka"));

	printf("%d\n", palindrome_avec_espace("kayak"));
	printf("%d\n", palindrome_avec_espace("la marie ira mal"));
	printf("%d\n", palindrome_avec_espace("karine alla en irak"));
	printf("%d\n", palindrome_avec_espace("kayAk"));
	printf("%d\n", palindrome_avec_espace("kayaka"));
	return 0;
}