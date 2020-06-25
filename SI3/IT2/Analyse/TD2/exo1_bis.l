comment "/*"([^*]|\*+[^*/])*\*+"/"
directive "#".*$
word auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
string \"([^\"]|\\.)*\"
lettre [^a-zA-Z]
keyword {lettre}{word}{lettre}


%option noyywrap

%{

void init( ){
     printf( "<!DOCTYPE html>\n<html>\n<head>\n<style>\nbody { background: #232323; color: #e6e1dc;}\n.comment { color: #bc9458; font-style: italic; }\n.directive { color: #9b859d; }\n.string { color: #a5c261; }\n.keyword { color: #c26230; font-weight: bold; }\n</style>\n<title>Pretty-print C</title>\n</head>\n<body>\n<pre>\n");
}

void span(char* style,char* str){
    printf( "<span class=%s>",style);
    print( str);
    printf( "</span>");
}


void print(char *str){
    for (int i=0;i<strlen(str);i++){
        if (*(str+i)=='<'){
             printf("&lt;");
        }
        else if (*(str+i)=='>'){
             printf("&gt");
        }
        else{
             printf("%c",*(str+i));
        }
    }
}


void directive(char* str){
     printf("<span class=directive>%s</span>",str);
}

void other(char* str){
     printf("%s",str);
}

void end(){
    printf("</pre>\n</body>\n</html>");
}
%}

%%       /* -------------------- début des régles */

{comment}           { span("comment",yytext); };
{directive}         { span("directive",yytext); };
{string}            { span("string",yytext); };
{keyword}           { span("keyword",yytext); };

.|\n                { other(yytext); };

%%      /* -------------------- début de la section code */
int main(int argc, char *argv[]) {

    init();
    yylex();
    end();
    return 0;
}
