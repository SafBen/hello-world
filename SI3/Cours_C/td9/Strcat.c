#include <stdlib.h>
#include <stdio.h>

// Antécédent : s1 et s2 deux chaines de caractères
// Conséquent : s1 recoit s1 + s2

void strCat(char s1[], const char s2[]){
  // s1 est une donnée et un résultat et s2 est une donnée
  // Premièrement : se positionner à la fin de s1
  // Deuxièment : ajouter les caractères de s2 dans s1
  int i=0;
  int j=0;
  while (s1[i] != '\0') i++;
    // on est placé à la fin de la chaîne s1
  while (s2[j] != '\0'){
    s1[i+j] = s2[j];
    j++;
  }
  s1[i+j] = '\0';
  // ou while(s1[i++] = s2[j++]) = "\0" correspond à 0 donc fin de boucle
  printf("%d",sizeof(s1));
}

int main(void){
  char s1[100] = "to";
  char const s2[] = "titi";
  strCat(s1,s2);
  printf("%s\n",s1);
  return EXIT_SUCCESS;
}
