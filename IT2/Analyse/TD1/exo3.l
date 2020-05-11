xxx [^"]|[\"]

%option noyywrap

%{ 
  #include <ctype.h>  /* pour toupper() */ 
%}

%%       /* -------------------- début des régles */

\"{xxx}*\"	{ for (int i=0;i<yyleng;i++)printf("%c",toupper(yytext[i])); }
.|\n			ECHO;

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
