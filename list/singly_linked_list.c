#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "singly_linked_list.h"

static Node *_allocNode(int value);
static Node *_getPrevNode(Node *head, Node *node);

// Initialize a list.
Node *initList(void)
{
	return NULL;
}

// Determine whether a list is empty or not.
bool isEmptyList(const Node *head)
{
	return head == NULL;
}

// Find a node whose value mathces the value parameter.
Node *findNode(Node *head, int value)
{
	if (head == NULL)
		return NULL;

	if (head -> value == value) 
		return head;
	else
		return findNode(head -> next, value);
}

// Insert a node at the beginning of the list.
void insertNode(Node **head, int value)
{
	Node *node = _allocNode(value);
	node -> next = *head;
	*head = node;
}

// Remove a node from a list.
void removeNode(Node **head, Node *node)
{
	Node *prev = _getPrevNode(*head, node);
	
	// node is the first node of the list.	
	if (prev == NULL)
		*head = node -> next;
	else
		prev -> next = node -> next;
		
	free(node); 
}

// Remove a node from a list with a double pointer.
void removeNodeWDoublePtr(Node **head, Node *node)
{
	Node *curr;
	Node **currPtr = head;

	for (curr = *head; curr != NULL; currPtr = &(curr -> next), curr = curr -> next) {
		if (curr == node) {
			*currPtr = curr -> next;
			free(curr);		
			break;
		}
	}
}

// Print a list.
void printList(Node *head)
{
	for (Node *curr = head; curr != NULL; curr = curr -> next) 
		printf("%d ", curr -> value);
	putchar('\n');
}

// Destroy a list.
void destroyList(Node **head)
{
	Node *next;
	while (*head != NULL) {
		next = (*head) -> next;
		free(*head);
		*head = next;
	}
	*head = NULL;
}	

int main(int argc, char *argv[])
{
	Node *head = initList();
	Node *node;
	char cmd[15];
	int value;	
	
	while (scanf("%s", cmd) != EOF) {
		if (!strcmp(cmd, "insert")) {
			printf("Insert value: ");
			scanf("%d", &value);
			insertNode(&head, value);

		} else if (!strcmp(cmd, "find")) {
			printf("Find value: ");
			scanf("%d", &value);
			node = findNode(head, value);

			if (node != NULL)
				printf("Value %d found\n", value);
			else
				printf("Value %d not found\n", value);

		} else if (!strcmp(cmd, "remove")) {
			printf("Remove value: ");
			scanf("%d", &value);
			node = findNode(head, value);
			findNode(head, value);
	
			if (isEmptyList(head)) {
				puts("Empty list");
			} else if (node == NULL) {
				printf("Value %d not found\n", value);
			} else {
				//removeNode(&head, node);
				removeNodeWDoublePtr(&head, node);
				printf("Value %d deleted\n", value);
			}

		} else if (!strcmp(cmd, "print")) {
			puts("Print the list");
			if (isEmptyList(head))
				puts("Empty list");
			else
				printList(head);

		} else if (!strcmp(cmd, "destroy")) {
			puts("Destroy the list");
			destroyList(&head);

		} else {
			puts("Wrong command");
		}
	}

	return 0;
}


static Node *_allocNode(int value)
{
	Node *node = calloc(1, sizeof(*node));
	node -> value = value;

	return node; 
}

static Node *_getPrevNode(Node *head, Node *node)
{
	if (head == NULL || head -> next == NULL)
		return NULL;

	if (head -> next == node)
		return head;
	else
		return _getPrevNode(head -> next, node);
}
