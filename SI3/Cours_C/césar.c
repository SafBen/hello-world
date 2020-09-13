#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
  int n;
  int c;
  scanf("%d\n",&n);
  while ( (c=getchar()) != EOF ){
    if (islower(c)){
      c+=n;
      if (c>"z")
	c-=26;
    }
    if (isupper(c)){
      c+=n;
      if (c>"Z")
	c-=26;
    }
  putchar(c);
  }
  return EXIT_SUCCESS;
}
