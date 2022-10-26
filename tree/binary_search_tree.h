#include <stdbool.h>

typedef struct _Node {
	int value;
	struct _Node *left;
	struct _Node *right;
} Node;

Node *initTree(void);
Node *insertNode(Node *root, int value);
bool isEmptyTree(Node *root);
int removeNode(Node **root, int value);
Node *findNode(Node *root, int value);
void traverseTree(Node *root);
void destroyTree(Node *root);
Node *findMin(Node *root);
Node *findMax(Node *root);
