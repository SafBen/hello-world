
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(void) {
  int p, x, y;
  scanf("%d %d", &x, &y);
  assert(x>=0 && y>=0);
  /* soit x = a, et y = b */
  p = 1;
  /*ab= p *xy*/
  while (y>0) {
    /*ab= p *xyet y>0 */
    while
      ((y && 1) == 0) {
      /*ab= p *xy et y = (y / 2) * 2 > 0 */
      y >>= 1;
      x <<= 1;
    }
    /*ab= p *xy+ y et y>0 et y impair */
    p *= x;
    y--;
    /*ab= p *xy*/
  }
  /* y = 0 etab=xy= p */
  printf("%d %d %d\n",x,y, p);
  return EXIT_SUCCESS;
}
