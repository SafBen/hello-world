#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
int main(void){
  int c, cpred;
  int nbCaracteres=0, nbLignes=0, nbMots = 0;
  while ((c=getchar()) != EOF){
    cpred = c;
    if (isspace(cpred) && !(isspace(c=getchar()))){
      nbMots ++;
      nbCaracteres ++;
    }
    else
      nbCaracteres ++;
    if (c =='\n')
      nbLignes ++;
  }
  printf("Caracteres = %d ; Lignes = %d ; Mots = %d\n",nbCaracteres, nbLignes, nbMots + 1);
}
*/

// Codage par automate

int main(void){
  int c;
  enum {horsmot , dansmot} etat = horsmot;
  int nbCaracteres=0, nbLignes=0, nbMots = 0;
  while ((c=getchar()) != EOF){
    // c est un caractère
    nbCaracteres ++;
    if (isspace(c)){
      // c n'est pas dans un mot
      if (etat == dansmot)
	etat = horsmot;
      if (c=='\n')
	// fin d'une ligne
	nbLignes ++;
    }
    else // c n'est pas un espace
      if (etat == horsmot){
	//
        etat = dansmot;
        nbMots ++;
      }
  }
  printf("Caracteres = %d ; Lignes = %d ; Mots = %d\n",nbCaracteres, nbLignes, nbMots);
}

