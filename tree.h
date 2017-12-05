/*
 * tree.h is based on USC's Data Structures and Algorithms binary tree implementation
 */

#ifndef GOPILER_TREE_H
#define GOPILER_TREE_H

/**
 * A tree is composed by nodes that store tokens and pointers to its left and right child nodes
 * Tokens are made out of a lexeme and identifier code, and should be modified if we wanted to
 * store more information.
 * The tree is ordered alphabetically by using the token's lexemes.
 */
typedef struct {
    char *lexeme;
    int code;
    float value;
    double (*func)();
} token;

typedef struct node {
    token *token;
    struct node *left;
    struct node *right;
} node;

typedef struct node *tree;

/**
 * Sets the starter pointer for a tree
 * @param tree *t, a tree pointer.
 */
void tree_init(tree *t);

/**
 * Given a tree, destroys all of its children and the tree itself and de-allocates the space used.
 * @param tree *t, a tree pointer.
 * @param token *k a token pointer.
 */
void tree_destroy(tree *t);

/**
 * Given a tree, and using a token's lexeme, finds the place where the token should be inserted
 * and allocates a space to store it.
 * @param tree *t, a tree pointer.
 * @param token *k a token pointer.
 */
void tree_set(tree *t, token *k);


/**
 * Given a tree, finds out whether or not a certain token is contained on the tree.
 * If the tree doesn't contain the token a NULL is returned.
 * @param tree *t, a tree pointer.
 * @param token *k a token pointer.
 * @return A token pointer or NULL.
 */
token *tree_get(tree t, token *k);

/**
 * Prints a tree node by node displaying a token's code and lexeme.
 * @param tree *t, a tree pointer.
 */
void tree_print(tree *t);


#endif //GOPILER_TREE_H
