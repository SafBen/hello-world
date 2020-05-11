%x STRING
%option noyywrap
%{ 
  #include <ctype.h>  /* pour toupper() */ 
%}
%%       /* -------------------- début des régles */

\"                { putchar('"'); BEGIN STRING; }
<STRING>\"        { putchar('"'); BEGIN INITIAL; }
<STRING>\\.       { printf("%s", yytext); }
<STRING>.         { putchar(toupper(*yytext)); }

.|\n                 { ECHO; }

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
