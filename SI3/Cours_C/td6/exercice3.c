#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ce programme recopie l'entrée standard en numérotant les lignes
// mais ici on a un chiffre en trop à la fin
/*
int main(void){
  int c;
  int numeroLigne = 1;
  printf("%d ",numeroLigne);
  while ((c=getchar()) != EOF){
    putchar(c);
    if (c=='\n'){
      numeroLigne ++;
      printf("%d ",numeroLigne);
    }
  }
  // fdf(stdin)
  return EXIT_SUCCESS;
}
*/
// même programme sans le dernier chiffre

int main(void){
  int c;
  int cpredecesseur = '\n'; // on initiale pour rentrer dans le premier if et ainsi écrire le numéro de la première ligne
  int numeroLigne = 1;
  while ((c=getchar()) != EOF){
    if (cpredecesseur == '\n'){
      // c est le premier caractère d'une nouvelle ligne
      printf("%d ",numeroLigne);
      numeroLigne ++;
    }
    // on écrit c
    putchar(c);
    cpredecesseur = c;
  }
  // fdf(stdin)
  return EXIT_SUCCESS;
}
