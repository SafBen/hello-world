#include <stdlib.h>
#include <stdio.h>

int appartientCercle(int a,int b,int r,int x,int y){
  // c = (a,b) centre du cercle
  // r = rayon du cercle
  // M = (x,y= est le point dont on veut tester son appartenance au cercle
  if (x*x+y*y<=1)
    return 1;
  else
    return 0;
}

int nombrePointsDansCercle(int a, int b, int r, int n){
  int i = 0;
  int x,y;
  int q = 0; //q compte le nombre de points dans le cercle
  while (i<n){
    //on donne n points pris aléatoirement dans [0;1]
    x = drand48();
    y = drand48();
    i++;
    if (appartientCercle(a,b,r,x,y))
      //on incrémente q
      q++;
  }
  return q;
}

double evalPi(int n){
  //on évalue le nombre pi à partir de la méthode de Monte-Carlo
  return 4*nombrePointsDansCercle(0,0,1,n)/n;
}
    

int main(void){
  int n;
  scanf("%d",&n);
  printf("pi = %f\n",evalPi(n));
}
  
