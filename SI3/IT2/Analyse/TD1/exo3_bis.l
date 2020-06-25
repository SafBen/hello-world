%x STRING
%x IN_COMMENT
%option noyywrap
%{ 
  #include <ctype.h>  /* pour toupper() */ 
%}
%%       /* -------------------- début des régles */

"/*"                    ECHO; BEGIN IN_COMMENT;
<IN_COMMENT>"*/"        ECHO; BEGIN INITIAL;
<IN_COMMENT>.|\n        ECHO;
\"			ECHO; BEGIN STRING;
<STRING>\"	        ECHO; BEGIN INITIAL;
<STRING>.|\n		{ for (int i=0;i<yyleng;i++)printf("%c",toupper(yytext[i])); }
.|\n                    ECHO;

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
