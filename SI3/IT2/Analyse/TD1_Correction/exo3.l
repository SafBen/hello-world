
%option noyywrap

%{ 
  #include <ctype.h>  /* pour toupper() */ 
%}

%%       /* -------------------- début des régles */

\"([^\"]|\\.)*\"    { for (char *s = yytext; *s; s++) {
                        putchar(toupper(*s));
                        if (*s == '\\') putchar(*++s);
                      }
                    }

.|\n                 { ECHO; }			ECHO;

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
