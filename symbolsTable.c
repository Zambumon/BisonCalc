#include "symbolsTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* The table is internally structured as a tree. As we do not want to allow direct access to it
 * from the outside, static is used so the variable is only "seen" only in the file it's
 * declared in
 */
static tree table;

/**
 * "Private" function used to insert the keywords defined on "definitions.h"
 * @param char *lexeme, how the keyword will be represented on the code to analyze;
 * @param int code, an unique integer that identifies the keyword
 */
static void table_math(char *lexeme, int code, float value, void *func);

void table_init() {
    // Initialize the tree;
    tree_init(&table);
    // Insert keywords
//    table_math(char *lexeme, int code, float value, void *func);
    //CTES
    table_math("e", DEFINITIONS_CONSTANT, 2.7182, NULL);
    table_math("pi", DEFINITIONS_CONSTANT, 3.1416, NULL);
    table_math("phi", DEFINITIONS_CONSTANT, 1.618, NULL);
    table_math("gamma", DEFINITIONS_CONSTANT, 0.5772, NULL);
    table_math("L", DEFINITIONS_CONSTANT, (float) (6.023 * pow(10, 23)), NULL);
    //MATH FUNCTIONS
    table_math("abs", DEFINITIONS_FUNCTION, 0, fabsf);
    table_math("acos", DEFINITIONS_FUNCTION, 0, acos);
    table_math("asin", DEFINITIONS_FUNCTION, 0, asin);
    table_math("atan", DEFINITIONS_FUNCTION, 0, atan);

    table_math("cos", DEFINITIONS_FUNCTION, 0, cos);
    table_math("sin", DEFINITIONS_FUNCTION, 0, sin);
    table_math("tan", DEFINITIONS_FUNCTION, 0, tan);

    table_math("cosh", DEFINITIONS_FUNCTION, 0, cosh);
    table_math("sinh", DEFINITIONS_FUNCTION, 0, sinh);
    table_math("tanh", DEFINITIONS_FUNCTION, 0, tanh);

    table_math("log", DEFINITIONS_FUNCTION, 0, log);
    table_math("log10", DEFINITIONS_FUNCTION, 0, log10);
    table_math("exp", DEFINITIONS_FUNCTION, 0, exp);
    table_math("exp2", DEFINITIONS_FUNCTION, 0, exp2);
    table_math("sqrt", DEFINITIONS_FUNCTION, 0, sqrt);


}

void table_destroy() {
    tree_destroy(&table);
    table = NULL;
}

static void table_math(char *lexeme, int code, float value, void *func) {

    token *t = (token *) calloc(1, sizeof(token));
    t->code = code;
    // strdup allocates and copies the string.
    t->lexeme = strdup(lexeme);
    t->value = value;
    t->func = func;
    tree_set(&table, t);
}

token *table_get(char *string) {
    token *new = (token *) calloc(1, sizeof(token));
    new->lexeme = strdup(string);
    return tree_get(table, new);
}

void table_set(char *string, int code, float value, void *func) {
    // Check whether the token is on the tree
    token *new = (token *) calloc(1, sizeof(token));
    new->lexeme = strdup(string);
    new->code = code;
    new->value = value;
    new->func = func;

    token *aux = tree_get(table, new);

    //new element:
    if (aux == NULL) {
        tree_set(&table, new);
    } else if (aux->code == DEFINITIONS_CONSTANT) {
        //TODO
        printf("\nTODO: Display message, send it to error. Send error code\n");
        return;
    } else {
        aux->value = value;
        aux->func = func;
    }

}

void table_print() {
    printf("\n\n-----------TABLE OF SYMBOLS-----------\n\x1b[33m");
    tree_print(&table);
    printf("\x1b[0m-----------TABLE OF SYMBOLS-----------\n\n");
}