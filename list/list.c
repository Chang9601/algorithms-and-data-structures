#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "list.h"

static Node *_allocate_node(void)
{
	return malloc(sizeof(Node));
}

static Node *_precede_curr_node(Node *head, Node *node)
{
	if(head == NULL || head -> next == NULL)
		return NULL;
	if(head -> next == node)
		return head;
	else
		return _precede_curr_node(head -> next, node);
}

Node *initialize_list(void)
{
	return NULL;
}

bool is_empty_list(Node *head)
{
	return head == NULL;
}

Node *search_node(Node *head, int value)
{
	if(head == NULL)
		return NULL;
	if(head -> value == value)
		return head;
	else
		return search_node(head -> next, value);
}

void insert_node(Node **head, int value)
{
	Node *new_node = _allocate_node();
	new_node -> value = value;
	new_node -> next = *head;
	*head = new_node;
}

void delete_node(Node **head, Node *node)
{
	Node *prev_node = _precede_curr_node(*head, node);
	
	if(prev_node == NULL)
		*head = node -> next;
	else
		prev_node -> next = node -> next;
		
	free(node); 
}

void print_list(Node *head)
{
	while(head != NULL)
	{
		printf("%d ", head -> value);
		head = head -> next;
	}
	putchar('\n');
}

void destroy_list(Node **head)
{
	Node *next_node;
	while(*head != NULL)
	{
		next_node = (*head) -> next;
		free(*head);
		*head = next_node;
	}
	*head = NULL;
}	

int main(int argc, char *argv[])
{
	Node *head = initialize_list();
	Node *node;
	char cmd[15];
	int value;	
	
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "insert"))
		{
			printf("Insert value: ");
			scanf("%d", &value);
			insert_node(&head, value);
		}	
		else if(!strcmp(cmd, "search"))
		{
			printf("Search value: ");
			scanf("%d", &value);
			node = search_node(head, value);

			if(node != NULL)
				printf("Value %d found\n", value);
			else
				printf("Value %d not found\n", value);
		}
		else if(!strcmp(cmd, "delete"))
		{
			printf("Delete value: ");
			scanf("%d", &value);
			node = search_node(head, value);
			search_node(head, value);
	
			if(is_empty_list(head))
				puts("Empty list");
			else if(node == NULL)
				printf("Value %d not found\n", value);
			else
			{
				delete_node(&head, node);
				printf("Value %d deleted\n", value);
			}
		}
		else if(!strcmp(cmd, "print"))
		{
			puts("Print the list");
			if(is_empty_list(head))
				puts("Empty list");
			else
				print_list(head);
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the list");
			destroy_list(&head);
		}
		else
			puts("Wrong command");
	}

	return 0;
}
