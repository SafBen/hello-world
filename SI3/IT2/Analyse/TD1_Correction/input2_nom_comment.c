 

#include <stdio.h>


int x = 0;  

 


char *str[] = {
  "",                                            
  "Iâ€™m a string",                                
  "Another string with embedded \"quotes\"",     
  "and another one with a \"\\\" !!!",           
  "Printed text on\n2 lines",                    
  "The TAB character: '\t' or '\011' or '\x9'.", 
  "Two strings",   "line",              
  "A // comment in a string",                    
  "A string spanning \
   2 lines",                                     
   NULL,
};


int main () {
  for (char **p = str; *p; p++) {
    fputs(*p, stdout);
    fputc('\n', stdout);
  }
  x = + +x;
  if (x == 1) fputs("PERDU\n", stdout);
  return 0;
}
