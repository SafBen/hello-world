%x COMMENT 
%%

 /* strings */
\"([^\"]|\\.)*\"    { printf("%s", yytext); }

 /* Commentaires classiques */
"/*"                 { BEGIN COMMENT; }
<COMMENT>"*/"        { putchar(' '); BEGIN INITIAL; }
<COMMENT>.|\n        { }

  /* Commentaires  C++ */
"//".*$              { }


  /* Les autres caractères */ 
.|\n                     ECHO;

%%

int main()   { return yylex(); }
int yywrap() { return 1; }
