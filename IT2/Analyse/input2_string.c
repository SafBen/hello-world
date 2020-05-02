/*
 * input2.c       -- Un programme avec des chaÃ®nes et des commentaires
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date: 31-Aug-2016 15:00 (eg)
 * Last file update: 24-Apr-2017 17:22 (eg)
 */

#include <stdio.h>

// Un commentaires Ã  la C++
int x = 0;  // Un commentaire C++ sur la fin de la ligne

/* un commentaire 'monoligne"  */


CHAR *STR[] = {
  "",                                            // TEST 0
  "Iâ€™M A STRING",                                // TEST 1
  "ANOTHER STRING WITH EMBEDDED \"QUOTES\"",     // TEST 2
  "AND ANOTHER ONE WITH A \"\\\" !!!",           // TEST 3
  "PRINTED TEXT ON\N2 LINES",                    // TEST 4
  "THE TAB CHARACTER: '\T' OR '\011' OR '\X9'.", // TEST 5
  "TWO STRINGS", /* ON A */ "LINE",              // TEST 6
  "A // COMMENT IN A STRING",                    // TEST 7
  "A STRING SPANNING \
   2 LINES",                                     // TEST 8
   NULL,
};


INT MAIN () {
  FOR (CHAR **P = STR; *P; P++) {
    FPUTS(*P, STDOUT);
    FPUTC('\N', STDOUT);
  }
  X = +/*UN COMMENTAIRE*/+X;
  IF (X == 1) FPUTS("PERDU\N", STDOUT);
  RETURN 0;
}
