%x IN_COMMENT
%x DOUBLE_COMMENT
%x STRING

comment "/*"([^*]|\*+[^*/])*\*+"/"
directive "#"([ -z]*)">"
keyword auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
string \"([^\"]|\\.)*\"

%option noyywrap

%{
#include <stdlib.h>
#include <stdio.h>

void initFile(FILE* file){
    fprintf(file,"<!DOCTYPE html>\n<html>\n<head>\n<style>\nbody { background: #232323; color: #e6e1dc;}\n.comment { color: #bc9458; font-style: italic; }\n.directive { color: #9b859d; }\n.string { color: #a5c261; }\n.keyword { color: #c26230; font-weight: bold; }\n</style>\n<title>Pretty-print C</title>\n</head>\n<body>\n<pre>\n");
}

void span(FILE* file,char* style,char* str){
    fprintf(file,"<span class=%s>%s</span>",style,str);
}

void other(FILE* file, char* str){
    fprintf(file,"%s",str);
}

void endFile(FILE* file){
    fprintf(file,"</pre>\n</body>\n</html>");
}
%}

%%       /* -------------------- début des régles */

{comment}       { printf("%s",yytext); };
{directive}     { printf("%s",yytext); };
{keyword}       { printf("%s",yytext); };
{string}       { printf("%s",yytext); };

.|\n                    { printf("%s",yytext); };

%%      /* -------------------- début de la section code */
int main(int argc, char *argv[]) {
   
    yylex();

    return 0;
}
