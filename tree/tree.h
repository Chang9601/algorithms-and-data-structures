#include <stdbool.h>

typedef struct _BSTNode {
	int value;
	struct _BSTNode *left, *right;
} BSTNode;

BSTNode *initialize_bst(void);
BSTNode *insert_bnode(BSTNode *root, int value);
bool is_empty_bst(BSTNode *root);
int delete_bnode(BSTNode **root, int value);
BSTNode *search_bnode(BSTNode *root, int value);
void traverse_bst(BSTNode *root);
void destroy_bst(BSTNode *root);
BSTNode *find_minimum(BSTNode *root);
BSTNode *find_maximum(BSTNode *root);
