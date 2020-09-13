#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Ce programme compte le nombre de lettres, de chiffres et d'espaces d'un fichier

int main(void){
  int c;
  int nbLettre = 0, nbChiffre = 0, nbEspace = 0;
  while ((c=getchar()) != EOF){
    if (isalpha(c))
    nbLettre ++;
    if (isdigit(c))
    nbChiffre ++;
    if (isspace(c))
    nbEspace ++;
  }
  printf("Lettre = %d ; Chiffre =  %d ; Espace =  %d\n",nbLettre,nbChiffre,nbEspace);
}
