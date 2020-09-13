#include <stdlib.h>
#include <stdio.h>

//Strlen Rôle calculer la longueur d'une chaine de caractère

int Strlen (const char s[]){
  int i=0;
  while (s[i] != '\0') i++;
  return i;
}

//Strchr(t,c) Rôle renvoyer l'indice de la première occurence de c du tableau t

int Strchr(const char s[],const char c){
  int i=0;
  while (s[i] != '\0'){
    if (s[i]==c) return i;
    i++;
  }
  return c=='\0' ? i:-1;
} 

int main(){
  char s[] = "bonjour";
  char c;
  scanf("%s\n",&c);
  printf("longueur = %d, occurence = %d\n",Strlen(s),Strchr(s,c));
  return EXIT_SUCCESS;
}