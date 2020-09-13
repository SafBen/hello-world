#include <stdio.h>
#include <stdlib.h>
#define MAXCAR 100
#include <assert.h>
#include <string.h>

typedef struct {
  char s[MAXCAR];
  int lg;
}String;

String string(const char s[]){
  String ss;
  ss.lg=strlen(s);
  assert(ss.lg<MAXCAR);
  strcpy(ss.s,s);
  return ss;
}

void ecrireString(const String s){
  printf("%s",s.s);
}

void ecrireLnString(const String s){
  ecrireString(s);
  printf("\n");
}

String stringCpy(String s){
  return s;
}

String stringCat(const String s1,String const s2){
  String ss;
  ss.lg=s1.lg+s2.lg;
  assert(ss.lg<MAXCAR);
  strcat(strcpy(ss.s,s1.s),s2.s);
  return ss;
}

int main(void){
  String s1 = string("hello");
  ecrireLnString(s1);
  
  String  s2 = stringCpy(s1);
  ecrireLnString(s2);
  
  String  s3 = stringCat(s1,s2);
  ecrireLnString(s3);
  
  for(int i=0; i<5; i++){
    s1 = stringCat(s1,s2);
    printf("%s",s1);}
  return EXIT_SUCCESS;
}
