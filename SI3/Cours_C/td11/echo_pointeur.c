#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  if (argc == 1) printf("\n");
  else {
    while (--argc > 1){
      printf("%s ",*++argv);
    }
    printf("%s\n",*(argv+1));
  }
  return 1;
}
