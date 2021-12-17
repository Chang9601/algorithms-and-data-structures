#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static BSTNode *_allocate_bnode(void)
{
	return malloc(sizeof(BSTNode));
}

BSTNode *initialize_bst(void)
{
	return NULL;
}

BSTNode *insert_bnode(BSTNode *root, int value)
{
	if(root == NULL)
	{
		root = _allocate_bnode();
		root -> left = root -> right = NULL;
		root -> value = value;
	}
	else if(root -> value == value)
		printf("%d already in the bst.\n", value);
	else if(root -> value < value)
		root -> right = insert_root(root -> right, value);
	else
		root -> left = insert_root(root -> left, value);
	
	return root;
}

bool is_empty_bst(BSTNode *root)
{
	return root == NULL;
}

int delete_bnode(BSTNode **root, int value)
{

}

BSTNode *search_bnode(BSTNode *root, int value)
{
	if(root == NULL)
		return NULL
	else if(root -> value == value)
		return root;
	else if(root -> value < value)
		return search_bnode(root -> right, value);
	else
		return search_bnode(root -> left, value);
}

void traverse_bst(BSTNode *root)
{
	if(root != NULL)
	{
		traverse_bst(root -> left);
		printf("%d\n", root -> value);
		traverse_bst(root -> right);
	}
}

void destroy_bst(BSTNode *root)
{
	if(root != NULL)
	{
		destroy_bst(root -> right);
		destroy_bst(root -> left);
		free(root);
	}
}

