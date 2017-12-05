#ifndef LEX_YY
#define LEX_YY

#include "syntax.tab.h"
#include "symbolsTable.h"
#include "definitions.h"
#include "utils.h"

void loadFile(char *filename);
int yyparse();

#endif //LEX_YY
