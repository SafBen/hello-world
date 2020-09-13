#include <stdlib.h>
#include <stdio.h>

#define MAXCAR 100

void afficherInverse(char ligne[],int n){
  for (int i=n-1 ; i>=0 ; i--)
    putchar(ligne[i]);
  putchar('\n');
}

int main(void){
  char ligne[MAXCAR];
  int c, i = 0;
  while ((c=getchar())!=EOF){
    if (c=='\n'){
      // on a fini de lire une ligne de l'entrée standard
      // tous les i caractères sont dans le tableau ligne
      afficherInverse(ligne,i);
      i = 0;
    }
    else{
      if (i<MAXCAR)
	ligne[i++]=c;
    }
  }
  // tester i = 0 ?
  return EXIT_SUCCESS;
}
