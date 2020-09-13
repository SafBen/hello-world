#include <stdlib.h>
#include <stdio.h>

int compare(char const s1[], char const s2[]){
  int i=0;
  while (s1[i] == s2[i] && s1[i] != '\0') i++;
  /*if (s1[i]<s2[i]) return -1;
  if (s1[i]>s2[i]) return 1;
  return 0;
  */
  return s1[i] - s2[i];
  // ou on enlève les 2 if et on fait s1[i]-s2[i]
}

int main(void){
  char s1[] = "toti";
  char s2[] = "toto";
  printf("%d  %d  %d\n",compare(s1,s2),compare(s2,s1),compare(s2,s2));
  return 1;
}
