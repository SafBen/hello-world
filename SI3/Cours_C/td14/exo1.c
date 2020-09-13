#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/*
 * Antécédent
 * Rôle
 */

void creerFichEntiers(char *f, int n){
  FILE *fd;
  int x;
  
  if ((fd=fopen(f, "w")) == NULL) {
    perror(f);
    exit(errno);
  }
  while (n-->0){
    x = rand()%10;
    fwrite(&x,sizeof(int),1,fd);
  }
  fclose(fd);
}

/*
 * Antécédent : ...
 * Rôle : ...
 */

void afficherFichEntiers(char *f){
  FILE *fd;
  int x;

  if ((fd=fopen(f, "r")) == NULL) {
    perror(f);
    exit(errno);
  }
  while(fread(&x,sizeof(int),1,fd)>0){
    printf(" %d ",x);
  }
  printf("\n");
  fclose(fd);
}

void PairsImpairs(char *f, char *fPairs, char *fImpairs){
  FILE *fd, *fp, *fi;
  int x;
  if ((fd=fopen(f, "r")) == NULL) {
    perror(f);
    exit(errno);
  }

  if ((fp=fopen(fPairs, "w")) == NULL) {
    perror(f);
    exit(errno);
  }
  if ((fi=fopen(fImpairs, "w")) == NULL) {
    perror(f);
    exit(errno);
  }
  
  while(fread(&x,sizeof(int),1,fd)>0){
    if (x & 1) // x est impair
      fwrite(&x,sizeof(int),1,fi);
    else // x est pair
      fwrite(&x,sizeof(int),1,fp);
  }
  
  fclose(fd);
  fclose(fp);
  fclose(fi);
  
}
  
int main(int argc, char *argv[]){
  creerFichEntiers(argv[1],15);
  afficherFichEntiers(argv[1]);
  PairsImpairs(argv[1],argv[2],argv[3]);
  printf("----------------\n");
  afficherFichEntiers(argv[2]);
  printf("----------------\n");
  afficherFichEntiers(argv[3]);
  return 1;
}
