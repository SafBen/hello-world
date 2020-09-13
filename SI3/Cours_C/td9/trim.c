#include <stdlib.h>
#include <stdio.h>

void trim(const char s1[], char s2[]){
  int i=0;
  int j=1;
  while (isspace(s1[i])) i++;
  while (isspace(s1[-j])) j++;
  for (int k=i,strlen(s1)-j,1){
    s2[k-i] = s1[k];
  }
  return s2;
}

int main(){
  char s1;
  char s2;
  scanf("%s\n",&s1);
  s2 = trim(s1);
  printf("%s\n",s2);
  return 1;
}
