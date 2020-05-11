ligne [\n]
mot [^ \t\n]
%option noyywrap

%{ /* Code C */
   int cpt_mots = 0, cpt_lignes = 0, cpt_char = 0;
%}

%%       /* -------------------- début des régles */

{ligne}			{ cpt_lignes += 1; cpt_char += 1; }
{mot}+			{ cpt_mots += 1; cpt_char += yyleng;}
.                 	{ cpt_char += 1; }

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    printf("Lignes: %d Mots: %d Char: %d\n", cpt_lignes, cpt_mots, cpt_char);
    return 0;
}
