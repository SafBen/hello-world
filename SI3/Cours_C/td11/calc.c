#include <stdlib.h>
#include <stdio.h>

// atoi = ascii to integer

int main(int argc, char *argv[]){
  if (argc != 4){
    fprintf(stderr,"Usage : calc int (+,-,\*,/) int");
    exit EXIT_FAILURE;
  }
  if (!est_un_entier(argv[1])){
    fprintf(stderr,"erreur");
    exit EXIT_FAILURE;
  }
  int opg = atoi(argv[1]);
  int opd = atoi(argv[3]);
  switch (*argv[2]) { // pas * ==> argv[][]
  case '+' : printf("%d\n", opg + opd); break;
  case '-' : printf("%d\n", opg - opd); break;
  case '*' : printf("%d\n", opg * opd); break; // il faut mettre \* dans le terminal car * existe déjà
  case '/' : printf("%d\n", opg / opd); break;
  }
  return 1;
}

int est_un_entier(const char *s){
  if (*s=='\0') return 0;
  while (*s){
    if (!isdigit(*s)) return 0;
    s++;
  }
  return 1;
}

int est_un_operateur(const char *s){
  return ((*s=='+' || *s=='-' || *s=='*' || *s=='/') && *(s+1)=='\0');
}
