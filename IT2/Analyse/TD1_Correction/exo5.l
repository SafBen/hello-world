signe      [+-]
digit      [0-9]
nombre     {digit}+
exposant   [eE]{signe}?{digit}+

reel        {signe}?(({nombre}\.?{digit}*)|\.{nombre}){exposant}?

%option noyywrap

%%       /* -------------------- début des régles */

{reel}     printf("<NOMBRE '%s'>", yytext);
.|\n       ECHO;

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
