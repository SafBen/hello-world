nombre ([+]?|[-]?)([.]?[0-9]*[eE]?[0-9]*|[0-9]*[.]?[eE]?[0-9]*|[0-9]*[.]?[0-9]*[eE]?[0-9]*)

%option noyywrap

%%       /* -------------------- début des régles */

{nombre}	{ printf("NOMBRE"); }
.|\n			ECHO;

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
