#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"

#define TAILLEZONEAFFICHAGE 260

void init_display(int argc, char **argv, void *d) {
  ValeurCourante *vc = d;

  Widget
    BQuit,
    BDollars,
    BEuros,
    ZoneSaisie;

  ZoneSaisie = MakeStringEntry(NULL, TAILLEZONEAFFICHAGE, NULL, d);
  setZoneSaisie(vc, ZoneSaisie);

  BQuit = MakeButton("Quit", quit, NULL);
  BDollars = MakeButton("Dollars", dollars, d);
  BEuros = MakeButton("Euros", euros, d);

  SetWidgetPos(BQuit, PLACE_UNDER, ZoneSaisie, NO_CARE, NULL);
  SetWidgetPos(BDollars, PLACE_RIGHT, BQuit, PLACE_UNDER, ZoneSaisie);
  SetWidgetPos(BEuros, PLACE_RIGHT, BDollars, PLACE_UNDER, ZoneSaisie);

  GetStandardColors();

  ShowDisplay();
}

int main(int argc, char *argv[]) {
  ValeurCourante d;
  if (OpenDisplay(argc, argv) == 0) {
    fprintf(stderr,"Can't open display\n");
    return EXIT_FAILURE;
  }

  initValeurCourante(&d);
  init_display(argc, argv, &d);
  MainLoop();

  return EXIT_SUCCESS;
}
