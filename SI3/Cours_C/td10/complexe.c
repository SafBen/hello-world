#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

/* le type  Complexe  représente  les  nombres  mathématiques  complexes  */
typedef  struct{
  double reel;
  double img;
} Complexe;

void ecrireComplexe( const Complexe c){
  printf("(%lf,%lf)\n",c.reel,c.img);
}
Complexe initComplexe(double r, double i){
  Complexe c;
  c.reel=r;
  c.img=i;
  return c;
}
double partieReelle(const Complexe c){
  return c.reel;
}
double partieImaginaire(const Complexe c){
  return c.img;
}
double rho( const Complexe c){
 return sqrt(partieReelle(c)*partieReelle(c)+partieImaginaire(c)*partieImaginaire(c));
}
double theta(const Complexe c){
  return atan2(partieImaginaire(c),partieReelle(c));
}
Complexe  polComplexe(double rho ,double theta){
  Complexe c;
  c.reel=rho*cos(theta);
  c.img=rho*sin(theta);
  return c;

}
Complexe plus(const Complexe a,const Complexe b){
  Complexe c={partieReelle(a)+partieReelle(b), partieImaginaire(a)+ partieImaginaire(b)};
  return c;
}
Complexe  moins(const Complexe a,const  Complexe b){
  Complexe c={partieReelle(a)-partieReelle(b), partieImaginaire(a)-partieImaginaire(b)};
  return c;
}
Complexe  mult(const Complexe a,const Complexe b){
  double rho2=rho(a)*rho(b);
  double theta2=theta(a)+theta(b);
  return polComplexe(rho2,theta2);
}
Complexe  divi(Complexe a, Complexe b){
  double rho2=rho(a)/rho(b);
  double theta2=theta(a)-theta(b);
  return polComplexe(rho2,theta2);
  
}
int main(void){
  const Complexe I= {0.0,1.0};
  const Complexe A= {2.0,1.0};
  const Complexe B= {1.0,2.0};
  ecrireComplexe(A);
  //ecrireComplexe(initComplexe(0,1));
  ecrireComplexe(B);
  ecrireComplexe(plus(A,B));
  ecrireComplexe(moins(A,B));
  ecrireComplexe(mult(A,B));
  ecrireComplexe(divi(A,B));
  
  // printf("%lf\n",partieReelle(I));
  //printf("%lf\n",partieImaginaire(I));
  //printf("rho=%lf\n",rho(I));
  //printf("theta=%lf\n",theta(I));
  //ecrireComplexe(polComplexe(1,PI/2));
  return EXIT_SUCCESS;
}
