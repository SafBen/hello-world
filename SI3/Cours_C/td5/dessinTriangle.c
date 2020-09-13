#include <stdlib.h>
#include <stdio.h>

//Antécédent : n > 0
//Conséquent : n étoiles ont été écrit sur la sortie standard

void ecrireEtoile(int n){
  int i = 0;
  //i étoiles ont été écrite sur la sortie standard
  while (i<n){
    i++;
    printf("*");
  }
}
// comme ecrireEtoile mais on passe à la ligne
void ecrireEtoileln(int n){
  ecrireEtoile(n);
  printf("\n");
}

//Antécédent : n>=0, longueur du triangle isocèle à tracer
//Conséquent : triangle isocèle AB = AC = n et tracé sur la sortie standard

void isocele1(int n){
  int i = 0;
  //triangle isocèle de côté 1
  while (i < n){
    i++;
    //écrire i étoiles
    ecrireEtoileln(i);
  }
  // triangle isocèle de côté i = n a été tracé
}

//Antécédent : n>0
//Conséquent:triangle isocèle de côté BC=2n-1 et tracé sur la sortie standard

void isocele2(int n){
  int i = 0;
  //triangle isocèle de côté 1
  while (i<n){
    i++;
    ecrireEtoileln(i);
  }
  // i = n
  while (i>0){
    i--;
    ecrireEtoileln(i);
  }
  /* ou isocele1miroir  */
}

//Antécédent : n>0
//Conséquent : on affiche n espaces

void espace(int n){
  int i = 0;
  // i = 0 pas d'espace
  while (i<n){
    i++;
    printf(" ");
  }
  // n espaces ont été fait sur une même ligne
}

//Antécédent : n>0
//Conséquent : triangle isocèle de côté BC = 2n-1 et de hauterur n symétrique par rapport à l'axe 

void isocele3(int n){
  int i = 0;
  //triangle isocèle de hauteur i = 0
  while (i<n){
    i++;
    espace(n-i);
    ecrireEtoileln(2*i-1);
  }
  //triangle isocèle de hauteur i = n
}
  
int main(void){
  int n;
  scanf("%d",&n);
  isocele3(n);
}
