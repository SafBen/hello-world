#include <stdio.h>
#include <string.h>

int palindrome(const char str[]){
	int n =strlen(str);
	for (int i = 0;i<n/2;i++){
		if (str[i]!=str[n-1-i]) return 0;
	}
	return 1;
}

int main(){
	printf("%d\n", palindrome("ressasser"));
	printf("%d\n", palindrome("kayak"));
	printf("%d\n", palindrome("X"));
	printf("%d\n", palindrome("test"));
	return 0;
}