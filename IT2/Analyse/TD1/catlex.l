/* La commande cat en lex */
%%
.|\n         {ECHO;}
%%
int main()  { return yylex(); }
int yywrap() { return 1; }
