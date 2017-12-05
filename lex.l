%{
#include "lex.yy.h"
#include <string.h>
%}

%option noyywrap

INTEGER [[:digit:]_]+
FLOAT   [[:digit:]]*\.[[:digit:]]+
EXP     [Ee][+-]?[[:digit:]_]+
ID      [[:alnum:]_]*
IGNORE  [[:blank:]]
PATH    [^\0\n]+

%x load

%%

<<EOF>>         {fclose(yyin); yyin = stdin; yyrestart(yyin);}

"load "      BEGIN(load);
<load>{PATH}  loadFile(yytext);
<load>";"|"\n" BEGIN(INITIAL);

"help"      {return HELP;}
"exit"      {return END;}
"table"     {return PRINT;}
"clear"     {return CLEAR;}
"constants" {return PRINT_CONSTANTS;}
"functions" {return PRINT_FUNCTIONS;}
"drop\ table" {return DROP_TABLE;}

{IGNORE}        {/*Do nothing*/}
{INTEGER}{EXP}  {yylval.num = atof(yytext); return NUMBER;}
{FLOAT}{EXP}    {yylval.num = atof(yytext); return NUMBER;}
{INTEGER}       {yylval.num = atof(yytext); return NUMBER;}
{FLOAT}         {yylval.num = atof(yytext); return NUMBER;}
{ID}            {yylval.id = (char *) malloc(sizeof (yytext));
                 yylval.id = strdup(yytext); return VARIABLE;}

";"|"\n"        {return EVAL;}
"("             {return LEFT_PARENTHESIS;}
")"             {return RIGHT_PARENTHESIS;}
"="             {return EQUALS;}
"+"             {return PLUS;}
"-"             {return MINUS;}
"*"             {return TIMES;}
"/"             {return DIVISION;}
"^"             {return POWER;}
.               {/*Do nothing*/}



%%

void loadFile(char *filename){
    if(filename != NULL){
        yyin = fopen(filename, "r");
        if(yyin == NULL){
            printError(ERROR_FILE);
            printf("%s",filename);
            yyin = stdin;
        }
    }else
        yyin = stdin;
}
