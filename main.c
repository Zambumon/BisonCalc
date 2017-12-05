#include <string.h>
#include "lex.yy.h"
#include "utils.h"
#include <stdio.h>
int main(int argc, char **argv){
    printf("\n\nBISON CALC\n");
    printf("Type \"help\" if you need any assistance\n");
    if(argc > 1){
        if(!strcmp(argv[1], "--help")) help();
        else loadFile(argv[1]);
    }

    table_init();
    yyparse();
    table_destroy();

    return 0;
}