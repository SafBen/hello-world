%{ 
  #include <ctype.h>  /* pour toupper() */ 
%}
%%
[a-z]         {printf("%c",toupper(yytext[0]));}
%%
int main()  { return yylex(); }
int yywrap() { return 1; }
