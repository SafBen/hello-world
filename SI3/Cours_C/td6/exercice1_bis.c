#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main(void){
  //l'entrée standard contien une suite de chiffres

  int n=0;
    int c;
    int neg=0;
  while(isspace(c=getchar()));//while vide
  // c est un caractere chiffre ou '+' ou '-'
  if(c=='+'||c=='-'){
    if(c=='-')neg=1;
    //passer au caract suivant
    c=getchar();
  }
  //c est un chiffre
  
  do{//c est un chiffre
    
    n=n*10+c-'0';//on multiplie fois 10 pour decaler chaque chiffre, et gerer le decenes ou centenes.
    //le 0=x, 1=x+1, 2=x+2, donc pour recuperer le variable on fait c-'0'
    
  }while(isdigit(c=getchar()));

  //n est égal au nombre lu sur l'entrée standard
  printf("%d\n",n);
  return EXIT_SUCCESS;
}
