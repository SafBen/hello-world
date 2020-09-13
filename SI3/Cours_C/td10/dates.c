#include <stdio.h>
#include <stdlib.h>
#define ANNEE_MIN 1589
#include <assert.h>
typedef struct {
  int jour,mois,annee;
  char nomDuMois[10];
}Date;
void ecrireDate(const Date d){
  assert(dateValide(d));
  printf("%d %s %d",d.jour,d.nomDuMois,d.annee);
}
//bissextile
int leap(int a){
  return (a%4==0 && a%100!=0) ||( a%400==0);
}
const char LesMois[][10]={"janvier","février","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","décembre"};

const int joursDansMois[]={31,28,31,30,31,30,31,31,30,31,30,31};

int nbrJoursDansMois(int m,int a){
  if(m==2) return leap(a)?29:28;
  return joursDansMois[m-1];
}
    
Date initDate(const int j,const int m,const int  a){
  Date d={j,m,a};
  assert(dateValide(d));
  //date valide
  strcpy(d.nomDuMois,LesMois[m-1]);
  return d;
}	 
Date lireDate(){
  int j,m,a;
  scanf("%d",&j);
  scanf("%d",&m);
  scanf("%d",&a);
  Date d={j,m,a};
  
  strcpy(d.nomDuMois,LesMois[m-1]);
  return d;
}
int dateValide(const Date d){
  if(d.annee< ANNEE_MIN){
    return 0;
  }
  if(1>d.mois|| d.mois>12){
    return 0;
  }
  int nbjours=nbrJoursDansMois(d.mois,d.annee);
  return d.jour>=1 && d.jour<=nbjours;
    
  
}
  


int main(void) {
  //lireDate();
  ecrireDate(initDate(27,1,2011));
  //ecrireDate(initDate (28,   2, 2017));
  printf("\n");
  ecrireDate(lireDate());
  return EXIT_SUCCESS;
}
