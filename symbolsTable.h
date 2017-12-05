#ifndef GOPILER_SYMBOLSTABLE_H
#define GOPILER_SYMBOLSTABLE_H

#include "tree.h"
#include "definitions.h"

/**
 * Creates a symbols table and stores the keywords defined by the Go Language.
 */
void table_init();

/**
 * Destroys a symbols table. Space used by the table is freed.
 */
void table_destroy();

/**
 * Tries to insert a token on the table.
 * @param token fields: string, code, value and function.
 * If a function isn't defined, NULL should be used.
 */
void table_set(char *string, int code, float value, void *func);
token *table_get(char *string);

/**
 * Prints a table displaying a token's code and lexeme.
 */
void table_print();


#endif //GOPILER_SYMBOLSTABLE_H
