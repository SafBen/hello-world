balise "</"[^>]*">"
bal "<"[^>]*">"
%x DEBUT
%x FIN
debut "<style>"|"<script>"
fin "</style>"|"</script>"

%option noyywrap



%%       /* -------------------- début des régles */

{debut}             BEGIN DEBUT;
<DEBUT>{fin}        BEGIN INITIAL;
<DEBUT>.|\n         {};
{balise}            {};
{bal}               {};
"&lt;"              {printf("<");};
"&gt;"              {printf(">");};
"&amp;"             {printf("&");};
"&quot;"            {printf("\"");};
"&nbsp;"            {printf(" ");};
"&#39;"             {printf("'");};
.|\n                ECHO;

%%      /* -------------------- début de la section code */
int main(int argc, char *argv[]) {

    yylex();

    return 0;
}
