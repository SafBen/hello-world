#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
int main(void){
  //L'entrée standard contient une suite de chiffres
  int c = getchar(); // on lit le premier caractère
  int n = 0;
  do { // c est un chiffre
    n = n*10 + c-'0';
  }
  while (isdigit(c=getchar()));
    //isdigit test si le paramètre est un chiffre
    //le caractère courant est un chiffre
  // n est égal au nombre lu sur l'entrée standard
  printf("%d\n",n*n);
  return EXIT_SUCCESS;
}


//isspace(c) test si paramètre est un espace
// essayer avec espace et précédé ou pas par + ou -
*/

int main(void){
  int c;
  int n = 0;
  int neg = 0; // par défaut c n'est pas négatif
  //sauter tous les espaces
  while (isspace(c=getchar()));
  //il n'y a rien à faire dans la boucle
  // c est un chiffre, + ou -
  if (c == '+' || c == '-') {
    if (c == '-'){
      neg = 1;
      n = -n;
    }
    c = getchar();
  } // c est un chiffre
  do { // c est un chiffre
    n = n*10 + c-'0';
  }
  while (isdigit(c=getchar()));
    //isdigit test si le paramètre est un chiffre
    //le caractère courant est un chiffre
  // n est égal au nombre lu sur l'entrée standard
  printf("%d\n",n);
  return EXIT_SUCCESS;
}
