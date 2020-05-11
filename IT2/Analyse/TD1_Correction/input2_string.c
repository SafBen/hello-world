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
  "Iâ€™m a string",                                // TEST 1
  "Another string with embedded \"QUOTES\"",     // test 2
  "AND ANOTHER ONE WITH A \"\\\" !!!",           // test 3
  "PRINTED TEXT ON\n2 LINES",                    // test 4
  "THE TAB CHARACTER: '\t' OR '\011' OR '\x9'.", // test 5
  "TWO STRINGS", /* on a */ "LINE",              // test 6
  "A // COMMENT IN A STRING",                    // test 7
  "A STRING SPANNING \
   2 LINES",                                     // test 8
   NULL,
};


int main () {
  for (char **p = str; *p; p++) {
    fputs(*p, stdout);
    fputc('\n', stdout);
  }
  x = +/*Un commentaire*/+x;
  if (x == 1) fputs("PERDU\n", stdout);
  return 0;
}
