%x IN_COMMENT
%x DOUBLE_COMMENT
%x STRING
%option noyywrap

%%       /* -------------------- début des régles */

"/*"                    BEGIN IN_COMMENT;
<IN_COMMENT>"*/"        BEGIN INITIAL;
<IN_COMMENT>.|\n        {};
\"			ECHO; BEGIN STRING;
<STRING>\"	        ECHO; BEGIN INITIAL;
<STRING>.|\n		ECHO;
"//"			BEGIN DOUBLE_COMMENT;
<DOUBLE_COMMENT>\n	ECHO; BEGIN INITIAL;
<DOUBLE_COMMENT>.	{};
.|\n                    ECHO;

%%      /* -------------------- début de la section code */
int main() {
    yylex();
    return 0;
}
