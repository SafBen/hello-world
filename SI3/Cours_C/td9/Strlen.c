

//Strlen Rôle calculer la longueur d'une chaine de caractère

int Strlen (const char s[]){
  int i=0;
  while (s[i] != '\0') i++;
  return i;
}

//Strchr(t,c) Rôle renvoyer l'indice de la première occurence de c du tableau t

int Strchr(const char s[],char c){
  int i=0;
  while (s[i] != 'c') i++;
  return i;
}

int main(){
  char s[] = "bonjour";
  char c;
  scanf("%c\n",&c);
  printf("longueur = %d, occurence = %d\n",Strlen(s),Strchr(s,c));
  return EXIT_SUCCESS;
}