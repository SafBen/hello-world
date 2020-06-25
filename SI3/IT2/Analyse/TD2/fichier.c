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

int main(int argc, char *argv[])
{
    FILE* fichier = NULL;

    fichier = fopen(argv[1], "w");

    initFile(fichier);
    span(fichier,"comment","/*\n* hello.c      -- Le classique Hello world en C\n*\n*/\n");
    span(fichier,"directive","#include &lt;stdio.h&gt;");
    other(fichier,"\n\n");
    span(fichier,"keyword","char");
    other(fichier," *w = ");
    span(fichier,"string","\"world\"");
    other(fichier,";\n\n");
    span(fichier,"keyword","int");
    other(fichier," main()  {\n  printf(");
    span(fichier,"string","\"Hello, %s.\\n\"");
    other(fichier,", w);\n  ");
    span(fichier,"keyword","return");
    other(fichier," 0;\n\n}");

    endFile(fichier);
    fclose(fichier);

    return 0;
}