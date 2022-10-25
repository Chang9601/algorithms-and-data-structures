#include <stdbool.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

Node *initList(void);
bool isEmptyList(const Node *head);
Node *findNode(Node *head, int value);
void insertNode(Node **head, int value);
void removeNode(Node **head, Node *node);
void removeNodeWDoublePtr(Node **head, Node *node);
void printList(Node *head);
void destroyList(Node **head);
