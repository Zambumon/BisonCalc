/*
 * tree.h is based on USC's Data Structures and Algorithms binary tree implementation
 */

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"


void tree_init(tree *t) {
    *t = NULL;
}

void tree_destroy(tree *t) {
    if (*t != NULL) {
        // Recursive function, starter by destroying the leaf nodes
        tree_destroy(&(*t)->left);
        tree_destroy(&(*t)->right);
        // Make sure that everything created so far is destroyed and set to NULL
        free((*t)->token->lexeme);
        (*t)->token->lexeme = NULL;
        free((*t)->token);
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->token = NULL;
        free(*t);
        *t = NULL;
    }
}


void tree_set(tree *t, token *k) {
    // Find the place where a token has to be set and alloc the space to store it.
    if (*t == NULL) {
        *t = (tree) calloc(1, sizeof(node));
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->token = k;

    } else if (strcmp(k->lexeme, (*t)->token->lexeme) < 0)
        tree_set(&(*t)->left, k);
    else if (strcmp(k->lexeme, (*t)->token->lexeme) > 0)
        tree_set(&(*t)->right, k);

}

token *tree_get(tree t, token *k) {
    if (t == NULL) // Token k isn't a node of the tree
        return NULL;

    int cmp = strcmp(k->lexeme, t->token->lexeme);

    if (cmp == 0) // The token is already on the tree
        return t->token;
    else if (cmp < 0)
        return tree_get(t->left, k);
    else
        return tree_get(t->right, k);

}

void tree_print(tree *t) {
    if (*t != NULL) {
        tree_print(&(*t)->left);
        switch((*t)->token->code){
            case DEFINITIONS_VARIABLE:
                printf("\x1b[34mVARIABLE    %-8s     <%f>\n", (*t)->token->lexeme, (*t)->token->value);
                break;
            case DEFINITIONS_CONSTANT:
                printf("\x1b[33mCONSTANT    %-8s     <%f>\n", (*t)->token->lexeme, (*t)->token->value);
                break;
            case DEFINITIONS_FUNCTION:
                printf("\x1b[36mFUNCTION    %-8s     <%p>\n", (*t)->token->lexeme, (*t)->token->func);
                break;
            default:
                break;
        }
        tree_print(&(*t)->right);
    }
}