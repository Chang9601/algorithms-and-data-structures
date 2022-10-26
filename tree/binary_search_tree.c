#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "binary_search_tree.h"

static Node *_allocNode(int value);
static Node *_getPrevNode(Node *node);
static Node *_getNextNode(Node *node);

// Initialize a tree.
Node *initTree(void)
{
	return NULL;
}

// Insert a node into a tree.
Node *insertNode(Node *root, int value)
{
	// Empty tree.
	if (root == NULL) {
		root = _allocNode(value);
	// value already in a tree.	
	} else if (root -> value == value) {
		printf("%d already in the tree.\n", value);
	// Move to a right subtree.	
	} else if (root -> value < value) {
		root -> right = insertNode(root -> right, value);
	// Move to a left subtree.	
	} else {
		root -> left = insertNode(root -> left, value);
	}
	
	return root;
}

// Determine if a tree is empty.
bool isEmptyTree(Node *root)
{
	return root == NULL;
}

// Remove a node from a tree.
int removeNode(Node **root, int value)
{
	Node *next, *temp;
	Node **ptr, **left;

	ptr = root;
	while (1) {

		if (*ptr == NULL) {
			return -1;
		} else if ((*ptr) -> value == value) {
			break;
		} else if ((*ptr) -> value < value) {
			ptr = &((*ptr) -> right);
		} else {
			ptr = &((*ptr) -> left);
		}
	}
	
	if ((*ptr) -> left == NULL) {
		next = (*ptr) -> right;
	} else {
		left = &((*ptr) -> left);
		while ((*left) -> right != NULL)
			left = &((*left) -> right);
	
		next = *left;
		*left = (*left) -> left;		
		next -> left = (*ptr) -> left;
		next -> right = (*ptr) -> right;
	}

	temp = *ptr;
	*ptr = next;	
	free(temp);

	return 0;
}

// Find a node whose value matches value.
Node *findNode(Node *root, int value)
{
	if (root == NULL) {
		return NULL;
	} else if (root -> value == value) {
		return root;
	} else if (root -> value < value) {
		return findNode(root -> right, value);
	} else {
		return findNode(root -> left, value);
	}
}

// Pre-order traversal in order to print values in an ascending order.
void traverseTree(Node *root)
{
	if (root != NULL) {
		traverseTree(root -> left);
		printf("%d\n", root -> value);
		traverseTree(root -> right);
	}
}

// Post-order traversal in order to destroy a tree.
void destroyTree(Node *root)
{
	if (root != NULL) {
		destroyTree(root -> left);
		destroyTree(root -> right);
		free(root);
	}
}

// Find a minimum value in a tree.
Node *findMin(Node *root)
{
	if (root == NULL)
		return NULL;
	while (root -> left  != NULL)
		root = root -> left;

	return root;
}

// Find a maximum value in a tree.
Node *findMax(Node *root)
{
	if (root == NULL)
		return NULL;
	while (root -> right  != NULL)
		root = root -> right;

	return root;
}

int main(int argc, char *argv[])
{
	Node *root = initTree();
	Node *node;
	char cmd[15];
	int value;	
	
	while (scanf("%s", cmd) != EOF) {

		if (!strcmp(cmd, "insert")) {
			printf("Insert value: ");
			scanf("%d", &value);
			root = insertNode(root, value);

		} else if (!strcmp(cmd, "find")) {
			printf("Find value: ");
			scanf("%d", &value);

			node = findNode(root, value);	
			if (node != NULL) {
				printf("Value %d found\n", value);
			} else {
				printf("Value %d not found\n", value);
			}

		} else if (!strcmp(cmd, "remove")) {
			printf("Remove value: ");
			scanf("%d", &value);
	
			if (isEmptyTree(root)) {
				puts("Empty tree");
			} else if (removeNode(&root, value) == -1) {
				printf("Value %d not found\n", value);
			} else {
				printf("Value %d deleted\n", value);
			}

		} else if (!strcmp(cmd, "traverse")) {
			puts("Traverse the tree");
			if(isEmptyTree(root)) {
				puts("Empty tree");
			} else {
				traverseTree(root);
			}
			putchar('\n');

		} else if (!strcmp(cmd, "destroy")) {
			puts("Destroy the tree");
			destroyTree(root);
			root = NULL;

		} else {
			puts("Wrong command");
		}
	}

	return 0;
}

static Node *_allocNode(int value)
{
	Node *node = calloc(1, sizeof(*node));
	node -> left = node -> right = NULL;
	node -> value = value;
}

static Node *_getPrevNode(Node *node)
{
	if (node -> left == NULL)
		return NULL;
	node = node -> left;

	while (node -> right != NULL)
		node = node -> right;

	return node;
}

static Node *_getNextNode(Node *node)
{
	if (node -> right == NULL)
		return NULL;
	node = node -> right;

	while (node -> left != NULL)
		node = node -> left;

	return node;
}
