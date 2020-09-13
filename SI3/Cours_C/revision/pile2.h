#pragma once  // pour éviter inclusions successives du même fichier .h


typedef void* T;

typedef struct noeud {
  T elt;
  struct noeud *suivant;
} *Pile; // Pile est un pointeur sur struct noeud

extern Pile pilevide(void);
extern Pile empiler(int,Pile);
extern int depiler(Pile);
extern T sommet(Pile);
extern int estvide(Pile);
