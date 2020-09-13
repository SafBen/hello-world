#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[]){
  int opt_n = 0;
  if (argc == 1) printf("\n");
  else {
    if (strcmp(*++argv,"-n")==0){ // 0 faux
      // l'option -n est présente
      // il faut mémoriser l'action
      opt_n = 1;
      // on icrémente argv pour se retrouver dans le même cas que s'il n'y avait pas -n
      argv++;
      argc--;
    }
    if (argc > 1) {
      // agrc >= 2
      while (--argc > 1)
	printf("%s ",*argv++);
      printf("%s",*argv);
    }
    if (!opt_n) printf("\n");
  }
  return 1;
}
