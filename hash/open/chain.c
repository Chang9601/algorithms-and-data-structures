#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chain.h"

static Node *_allocate_node()
{
	return malloc(sizeof(Node));
}

static int _hash_func(int key, int count)
{
	return key % count;
}

void initialize_table(ChainHash *hash, int count)
{
	hash -> count = count; 
	hash -> table = malloc(sizeof(Node *) * count);
	int i;
	for(i = 0; i < count; i++)
		hash -> table[i] = NULL;
}
	
Node *search_node(ChainHash *hash, int value)
{
	int key = _hash_func(value, hash -> count);
	
	for(Node *curr_node = hash -> table[key]; curr_node != NULL; curr_node = curr_node -> next)
		if(curr_node -> value == value)
			return curr_node;
	return NULL;
}

int insert_node(ChainHash *hash, int value)
{
	int key = _hash_func(value, hash -> count);
	
	for(Node *curr_node = hash -> table[key]; curr_node != NULL; curr_node = curr_node -> next)
	{
		if(curr_node -> value == value)
			return -1;
	}	

	Node *new_node = _allocate_node();
	new_node -> value = value;
	new_node -> next = hash -> table[key];
	// TO-DO
	hash -> table[key] = new_node;	

	return 0;
}

int delete_node(ChainHash *hash, int value)
{
	int key = _hash_func(value, hash -> count);

	Node *curr_node;
	Node **curr_node_ptr = &(hash -> table[key]);

	for(curr_node = hash -> table[key]; curr_node != NULL; curr_node_ptr = &(curr_node -> next), curr_node = curr_node -> next)
	{
		if(curr_node -> value == value)
		{	
			// TO-DO
			*curr_node_ptr = curr_node -> next;
			free(curr_node);
			return 0;
		}
	}	

	return -1;	
}

void dump_table(ChainHash *hash)
{
	int i;
	for(i = 0; i < hash -> count; i++)
	{
		printf("%02d ", i);
		for(Node *curr_node = hash -> table[i]; curr_node != NULL; curr_node = curr_node -> next)
			printf("-> %d", curr_node -> value);
		putchar('\n');
	}
}

void destroy_table(ChainHash *hash)
{
	int i;
	for(i = 0; i < hash -> count; i++)
	{	
		Node *curr_node = hash -> table[i];
		Node *next_node;
	
		while(curr_node != NULL)
		{
			next_node = curr_node -> next;
			free(curr_node);
			curr_node = next_node;
		}
		hash -> table[i] = NULL;
	}	

	hash -> count = 0;
	free(hash -> table);
}


int main(int argc, char *argv[])
{
	ChainHash hash;
	int count;
	printf("Enter the size of the hash table:");
	scanf("%d", &count);

	initialize_table(&hash, count);	

	char cmd[15];
	int value;	
	Node *node;
	
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "insert"))
		{
			printf("Insert value: ");
			scanf("%d", &value);
			if(insert_node(&hash, value) == -1)
				printf("Value %d already in the hash table", value);
			
		}	
		else if(!strcmp(cmd, "search"))
		{
			printf("Search value: ");
			scanf("%d", &value);
			node = search_node(&hash, value);

			if(node != NULL)
				printf("Value %d found\n", value);
			else
				printf("Value %d not found\n", value);
		}
		else if(!strcmp(cmd, "delete"))
		{
			printf("Delete value: ");
			scanf("%d", &value);
			
			if(delete_node(&hash, value) == 0)
				printf("Value %d deleted\n", value);
			else
				printf("Value %d not deleted\n", value);
					
				
		}
		else if(!strcmp(cmd, "dump"))
		{
			puts("Dump the hash table");
			dump_table(&hash);
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the hash table");
			destroy_table(&hash);
		}
		else
			puts("Wrong command");
	}

	return 0;
}
