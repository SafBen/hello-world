#include <stdlib.h>
#include <stdio.h>
#include "data.h"

void initValeurCourante(ValeurCourante *d) {
  d->tauxDeChange = 1.1;
}

void setZoneSaisie(ValeurCourante *d, Widget w) {
  d->ZoneSaisie = w;
}

void setValeur(ValeurCourante *d, double n) {
  d->valeur=n;
}

double getValeur(ValeurCourante *d) {
  return d->valeur;
}

void convertirEnDollars(ValeurCourante *d) {
  d->valeur = d->valeur * d->tauxDeChange;
}

void convertirEnEuros(ValeurCourante *d) {
  d->valeur = d->valeur / d->tauxDeChange;
}
