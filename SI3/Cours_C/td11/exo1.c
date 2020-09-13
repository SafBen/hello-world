/* 1) --> 4)

2) type incompatible

3) temp = 'A' puis W puis P puis A
   temp = P puis W
   */

#include <stdlib.h>
#include <stdio.h>


int swap(int *a, int *b){
  // a et b sont des données et des résultats
  int aux = *a;
  *a = *b;
  *b = aux;
}

int Strlen(const char *s){
  char *p = s;
  while(*s++); // '\0' codé par 0 donc faux c'est pour ça que ça termine
  return (s-1-p);
}

char *Strcat(char *s1, const char *s2){
  char *p = s1;
  while(*s1) s1++;
  // *s1 = '\0'
  while(*s1++ = *s2++)
  return p;
}

char *Strchr(char *s, const char c){
  while(*s){
    if (*s==c) return s;
    //
    s++;
  }
  // c n'appartient pas à s
  return NULL;
}

int main(){
  int x=2,y=6;
  swap(&x,&y);
  printf("%d %d\n",x,y);
  char c[10] = "abc";
  char *d = "xy";
  printf("%s\n",Strcat(c,d));
  printf("%c\n",Strchr(c,"b"));
  return 1;
}
    