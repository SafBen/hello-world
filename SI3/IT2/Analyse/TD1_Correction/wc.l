%{
  int chars = 0;
  int words = 0;
  int lines = 0;
%}

%%
[^\n\t ]+  { words += 1; chars += strlen(yytext); }
\n         { chars += 1; lines += 1; }
.          { chars += 1; }
%%

int main() {
    yylex();
    printf("%3d %3d %3d\n", lines, words, chars);
}

int yywrap() { return 1; }
