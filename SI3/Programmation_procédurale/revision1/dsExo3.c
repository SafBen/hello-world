#include <stdio.h>

int main(int argc, char const *argv[])
{
	char c;
	while ((c=getchar())!=EOF){
		if (c<='Z' && c>='A') // c est une majuscule
		{
			c=c-'A'+'a';
		}
		putchar(c);
	}
	putchar('\n');
	return 0;
}