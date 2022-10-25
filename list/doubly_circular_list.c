#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "doubly_circular_list.h"

static Node *_allocNode(int value);

// Initialize a list.
Node *initList(void)
{
	// Create a dummy node.
	Node *sentinel = _allocNode(0);
	sentinel -> prev = sentinel -> next = sentinel;

	return sentinel;
}

// Determine if a list is empty.
bool isEmptyList(const Node *head)
{
	// If there is only a sentinel node in the list.
	return head == head -> next;
}

// Find a node in a list.
Node *findNode(Node *head, int value)
{
	// head points to a sentinel, so the first node is head -> next
	for (Node *curr = head -> next; curr != head; curr = curr -> next)
		if (curr -> value == value)
			return curr;	

	return NULL;
}

// Insert a node at the beginning of a list.
void insertNodeAtFront(Node *head, int value)
{
	Node *node = _allocNode(value);

	node -> next = head -> next;
	node -> prev = head;
	node -> next -> prev = node;
	head -> next = node;
}

// Insert a node at the end of a list.
void insertNodeAtBack(Node *head, int value)
{
	Node *node = _allocNode(value);

	node -> next = head;
	node -> prev = head -> prev;
	node -> prev -> next = node;
	head -> prev = node;
}

// Remove a node from a list.
void removeNode(Node *head, Node *node)
{
	for (Node *curr = head -> next; curr != head; curr = curr -> next) {
		if (curr == node) {
			curr -> prev -> next = curr -> next;
			curr -> next -> prev = curr -> prev;
			free(node);
			break;
		}
	}
}

// Print a list.
void printList(Node *head)
{
	for (Node *curr = head -> next; curr != head; curr = curr -> next)
		printf("%d ", curr -> value);
	putchar('\n');
}

// Destroy a list.
void destroyList(Node *head)
{
	Node *curr = head -> next;
	Node *next;
	
	// sentinel is excluded.
	while (head != curr) {
		next = curr -> next;
		free(curr);
		curr = next;
	}

	// Reset the list.
	head -> prev = head -> next = head;
}

int main(int argc, char *argv[])
{
	Node *head = initList();
	Node *node;
	char cmd[15];
	int value;	
	
	while (scanf("%s", cmd) != EOF) {

		if (!strcmp(cmd, "insertF")) {
			printf("Insert value at the beginning: ");
			scanf("%d", &value);
			insertNodeAtFront(head, value);

		} else if (!strcmp(cmd, "insertB")) {
			printf("Insert value at the end: ");
			scanf("%d", &value);
			insertNodeAtBack(head, value);

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
	
			if (isEmptyList(head)) {
				puts("Empty list");
			} else if (node == NULL) {
				printf("Value %d not found\n", value);
			} else {
				removeNode(head, node);
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
				destroyList(head);

		} else {
			puts("Wrong command");
		}
	}

	// Free a sentinel.	
	free(head);

	return EXIT_SUCCESS;
}


static Node *_allocNode(int value)
{
	Node *node = calloc(1, sizeof(*node));
	node -> value = value;

	return node;
}
