#include <stdio.h>
#include <math.h>

int main() {
  printf("Avec le cast\n\n");
  printf("+-------+-----+\n");
  for (float c = 0.0; c <= 20.0; c += 0.5)
    printf("| %4.1fC | %2dF |\n", c, (int) (9*c)/5+32 );
  printf("+-------+-----+\n");

  printf("Avec le rint\n\n");
  printf("+-------+-----+\n");
  for (float c=0.0; c <= 20.0; c += 0.5)
    printf("| %4.1fC | %2.0fF |\n", c, rint((9*c)/5+32) );
  printf("+-------+-----+\n");
  
  return 0;
}