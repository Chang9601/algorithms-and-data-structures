#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

static BSTNode *_allocate_bstnode(void)
{
	return malloc(sizeof(BSTNode));
}

static BSTNode *_precede_curr_bstnode(BSTNode *root)
{
	if(root -> left == NULL)
		return NULL;
	root = root -> left;
	while(root -> right != NULL)
		root = root -> right;

	return root;
}

static BSTNode *_succeed_curr_bstnode(BSTNode *root)
{
	if(root -> right == NULL)
		return NULL;
	root = root -> right;
	while(root -> left != NULL)
		root = root -> left;

	return root;
}

BSTNode *initialize_bst(void)
{
	return NULL;
}

BSTNode *insert_bstnode(BSTNode *root, int value)
{
	if(root == NULL)
	{
		root = _allocate_bstnode();
		root -> left = root -> right = NULL;
		root -> value = value;
	}
	else if(root -> value == value)
		printf("%d already in the tree.\n", value);
	else if(root -> value < value)
		root -> right = insert_bstnode(root -> right, value);
	else
		root -> left = insert_bstnode(root -> left, value);
	
	return root;
}

bool is_empty_bst(BSTNode *root)
{
	return root == NULL;
}

int delete_bstnode(BSTNode **root, int value)
{
	BSTNode *next, *temp;
	BSTNode **p, **left;

	p = root;
	while(1)
	{
		if(*p == NULL)
			return -1;
		else if((*p) -> value == value)
			break;
		else if((*p) -> value < value)
			p = &((*p) -> right);
		else
			p = &((*p) -> left);
	}
	
	if((*p) -> left == NULL)
		next = (*p) -> right;
	else
	{
		left = &((*p) -> left);
		while((*left) -> right != NULL)
			left = &((*left) -> right);
	
		next = *left;
		*left = (*left) -> left;		
		next -> left = (*p) -> left;
		next -> right = (*p) -> right;
	}

	temp = *p;
	*p = next;	
	free(temp);

	return 0;
}

BSTNode *search_bstnode(BSTNode *root, int value)
{
	if(root == NULL)
		return NULL;
	else if(root -> value == value)
		return root;
	else if(root -> value < value)
		return search_bstnode(root -> right, value);
	else
		return search_bstnode(root -> left, value);
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
		destroy_bst(root -> left);
		destroy_bst(root -> right);
		free(root);
	}
}

BSTNode *find_minimum(BSTNode *root)
{
	if(root == NULL)
		return NULL;
	while(root -> left  != NULL)
		root = root -> left;

	return root;
}

BSTNode *find_maximum(BSTNode *root)
{
	if(root == NULL)
		return NULL;
	while(root -> right  != NULL)
		root = root -> right;

	return root;
}

int main(int argc, char *argv[])
{
	BSTNode *root = initialize_bst();
	BSTNode *bstnode;
	char cmd[15];
	int value;	
	
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "insert"))
		{
			printf("Insert value: ");
			scanf("%d", &value);
			root = insert_bstnode(root, value);
		}	
		else if(!strcmp(cmd, "search"))
		{
			printf("Search value: ");
			scanf("%d", &value);

			bstnode = search_bstnode(root, value);	
			if(bstnode != NULL)
				printf("Value %d found\n", value);
			else
				printf("Value %d not found\n", value);
		}
		else if(!strcmp(cmd, "delete"))
		{
			printf("Delete value: ");
			scanf("%d", &value);
	
			if(is_empty_bst(root))
				puts("Empty tree");
			else if(delete_bstnode(&root, value) == -1)
				printf("Value %d not found\n", value);
			else
				printf("Value %d deleted\n", value);
		}
		else if(!strcmp(cmd, "traverse"))
		{
			puts("Traverse the tree");
			if(is_empty_bst(root))
				puts("Empty tree");
			else
				traverse_bst(root);
			putchar('\n');
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the tree");
			destroy_bst(root);
			root = NULL;
		}
		else
			puts("Wrong command");
	}

	return 0;
}
