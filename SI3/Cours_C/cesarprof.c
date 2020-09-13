#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void){
  int c;
  int decalage;
  scanf("%d", &decalage);
  if (decalage <1 ||  decalage  > 25) {
    fprintf(stderr ,"Erreur : valeur  de  décalage  incorrecte");
    exit(EXIT_FAILURE );
  }
  while ((c=getchar ()) != EOF) {
    if (islower(c)) {
      c +=  decalage;
      if(c>"z") c -=26;
    }
    else if (isupper(c)) {
      c +=  decalage;
      if(c>"Z") c -=26;
    }
    putchar(c);
  }
  return EXIT_SUCCESS;
}
