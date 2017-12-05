%{
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "utils.h"
#include "symbolsTable.h"
#include "lex.yy.h"


void yyerror(char *s);
extern int yylex(void);
%}

//Collection of possible types for semantic values
%union{
float num;
char *id;
}


%start input


%token <num> NUMBER
%token <id> VARIABLE

//USER help and table_print
%token HELP
%token CLEAR
%token END
%token PRINT
%token PRINT_CONSTANTS
%token PRINT_FUNCTIONS
%token DROP_TABLE

%token EVAL
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS

// Must follow this order
%right EQUALS
%left PLUS
%left MINUS
%left TIMES
%left DIVISION
%left LEFT_PARENTHESIS
%left NEGATIVE
%right POWER


%type <num> EXPRESSION
%type <num> ASSIGN
%type <num> OPERATION

%%



input:  // Empty line
        | input line
;

line:   EVAL
        |EXPRESSION EVAL  {printf("%.4f\n", $1);}
        |HELP EVAL        {help();}
        |PRINT EVAL       {table_print();}
        |END EVAL         {YYACCEPT;}
        |CLEAR EVAL       {clear();}
        |PRINT_CONSTANTS  {constants();}
        |PRINT_FUNCTIONS  {functions();}
        |DROP_TABLE       {table_destroy(); table_init();printf("Symbols table dropped\n");}
;



EXPRESSION:
         NUMBER     {$$ = $1;}
        |ASSIGN
        |OPERATION
        |LEFT_PARENTHESIS EXPRESSION RIGHT_PARENTHESIS {$$ = $2;}
        |VARIABLE   {
            token *aux = table_get($1);
            if(aux) $$ = aux->value;
            else    yyerror(ERROR_NON_INITIALIZED_VARIABLE);
        }
        |VARIABLE LEFT_PARENTHESIS EXPRESSION RIGHT_PARENTHESIS    {
            token *aux = table_get($1);
            if(aux && aux->func) $$ = aux->func($3);
            else yyerror(ERROR_NOT_A_FUNCTION);
        }
;


OPERATION:
         EXPRESSION PLUS EXPRESSION       {$$ = $1 + $3;}
        |EXPRESSION MINUS EXPRESSION      {$$ = $1 - $3;}
        |EXPRESSION TIMES EXPRESSION      {$$ = $1 * $3;}
        |EXPRESSION DIVISION EXPRESSION   {if($3) $$ = $1 / $3; else yyerror(ERROR_DIVISION_BY_ZERO);}
        |MINUS EXPRESSION %prec NEGATIVE  {$$ = -$2;}
        |EXPRESSION POWER EXPRESSION      {$$ = pow($1, $3);}
;


ASSIGN:
        VARIABLE EQUALS EXPRESSION     {table_set($1, DEFINITIONS_VARIABLE, $3, NULL); $$ = $3;}
;



%%

void yyerror(char *s){printError(s);}


