#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


int estUnOperateur(char *s) {
  return (s[0]=='+' || s[0]=='-' || s[0]=='*' || s[0]=='/') && s[1]=='\0';
}


int main(int argc, char *argv[]) {
  Pile p = pilevide(); /* initialisation de la pile */
  int i;
  for (i=1; i<argc; i++)
    /* */
    if (estUnOperateur(argv[i])) {
      int opG, opD;
      /* traiter l'opérateur */
      /* prendre le premier opérande en sommet de pile */
      opD=sommet(p); depiler(&p);
      /* prendre le second opérande en sommet de pile */
      opG=sommet(p); depiler(&p);
      /* faire l'opération et empiler le résultat */
      switch (*argv[i]) {
      case '+' : empiler(opG+opD,&p); break;
      case '*' : empiler(opG*opD,&p); break;
      case '-' : empiler(opG-opD,&p); break;
      case '/' : if (opD!=0) empiler(opG/opD,&p);
	else {
	  fprintf(stderr,"division par zéro\n");
	  exit(EXIT_FAILURE);
	}
      }
    }
    else
      /* argv[i] est un opérande => l'empiler */
      empiler(atoi(argv[i]),&p);
  /* l'expression postifxée a été évaluée */
  /* afficher le résultat */
  printf("=> %d\n", sommet(p));
  return EXIT_SUCCESS;
}
