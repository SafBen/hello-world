#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"

void quit(Widget w, void *data) {
  exit(EXIT_SUCCESS);
}

static void afficher(ValeurCourante *d) {
  char *s = malloc(ZoneSaisieSIZE+1);
  sprintf(s,"%-f", getValeur(d));
  SetStringEntry(d->ZoneSaisie,s);
  free(s);
}

void dollars(Widget w, void *data) {
  ValeurCourante *d = data;
  setValeur(d, strtod(GetStringEntry(d->ZoneSaisie), NULL));
  convertirEnEuros(d);
  afficher(d);
}

void euros(Widget w, void *data) {
  ValeurCourante *d = data;
  setValeur(d, strtod(GetStringEntry(d->ZoneSaisie), NULL));
  convertirEnDollars(d);
  afficher(d);
}
