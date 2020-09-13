#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
  int c;
  while ((c=getchar()) != EOF)
    putchar(c);
  // fdf(stdin)
  return EXIT_SUCCESS;
}
