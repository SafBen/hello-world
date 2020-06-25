%x IN_COMMENT
%x DOUBLE_COMMENT
%x STRING
directive "#".*$

non_lettre [^a-zA-Z\n]
word auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
keyword {non_lettre}?{word}{non_lettre}

%option noyywrap

%%       /* -------------------- début des régles */

{directive}             ECHO; printf("\n");
{keyword}               ECHO;
"/*"                    BEGIN IN_COMMENT;
<IN_COMMENT>"*/"        BEGIN INITIAL;
<IN_COMMENT>.|\n        {};
\"			            ECHO; BEGIN STRING;
<STRING>\"	            ECHO; BEGIN INITIAL;
<STRING>.   		    ECHO;
"//"		    	    BEGIN DOUBLE_COMMENT;
<DOUBLE_COMMENT>\n	    BEGIN INITIAL;
<DOUBLE_COMMENT>.	    {};
\n|" "                  {};


%%      /* -------------------- début de la section code */
int main() {
    yylex();
    printf("\n");
    return 0;
}
