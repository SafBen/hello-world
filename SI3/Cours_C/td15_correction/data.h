#pragma once

#include <libsx.h>

#define ZoneSaisieSIZE 19

typedef struct {
  Widget ZoneSaisie;
  double tauxDeChange;
  double valeur;
} ValeurCourante;

extern void initValeurCourante(ValeurCourante *);
extern void setValeur(ValeurCourante *d, double n);
extern double getValeur(ValeurCourante *d);
extern void convertirEnDollars(ValeurCourante *d);
extern void convertirEnEuros(ValeurCourante *d);
extern void setZoneSaisie(ValeurCourante *d, Widget w);
