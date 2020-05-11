comment "/*"([^*]|\*+[^*/])*\*+"/"
directive "#".*$
word auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
string \"([^\"]|\\.)*\"
lettre [^a-zA-Z]
keyword {lettre}{word}{lettre}


%option noyywrap

%{

FILE* fichier = NULL;

void initFile(FILE* file){
    fprintf(file,"<!DOCTYPE html>\n<html>\n<head>\n<style>\nbody { background: #232323; color: #e6e1dc;}\n.comment { color: #bc9458; font-style: italic; }\n.directive { color: #9b859d; }\n.string { color: #a5c261; }\n.keyword { color: #c26230; font-weight: bold; }\n</style>\n<title>Pretty-print C</title>\n</head>\n<body>\n<pre>\n");
}

void span(FILE* file, char* style,char* str){
    fprintf(file,"<span class=%s>",style);
    print(file,str);
    fprintf(file,"</span>");
}


void print(FILE* file, char *str){
    for (int i=0;i<strlen(str);i++){
        if (*(str+i)=='<'){
            fprintf(file,"&lt;");
        }
        else if (*(str+i)=='>'){
            fprintf(file,"&gt");
        }
        else{
            fprintf(file,"%c",*(str+i));
        }
    }
}


void directive(FILE* file,char* str){
    fprintf(file,"<span class=directive>%s</span>",str);
}

void other(FILE* file, char* str){
    fprintf(file,"%s",str);
}

void endFile(FILE* file){
    fprintf(file,"</pre>\n</body>\n</html>");
}
%}

%%       /* -------------------- début des régles */

{comment}           { span(fichier,"comment",yytext); };
{directive}         { span(fichier,"directive",yytext); };
{string}            { span(fichier,"string",yytext); };
{keyword}           { span(fichier,"keyword",yytext); };

.|\n                { other(fichier,yytext); };

%%      /* -------------------- début de la section code */
int main(int argc, char *argv[]) {
    
    fichier = fopen(argv[1], "w");
    initFile(fichier);

    yylex();

    endFile(fichier);
    fclose(fichier);
    return 0;
}
