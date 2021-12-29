#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "open_address.h"

static int _hash_func(int key, int count)
{
	return key % count;
}

static int _rehash_func(int key, int count)
{
	return (key + 1) % count;
}

void initialize_table(ClosedHash *hash, int count)
{
	hash -> count = count;
	hash -> table = malloc(sizeof(Bucket) * count);

	int i;
	for(i = 0; i < count; i++)
		hash -> table[i].status = EMPTY;
}

Bucket *search_value(ClosedHash *hash, int value)
{
	int key = _hash_func(value, hash -> count);
	int i;
	Bucket *bucket = &(hash -> table[key]);

	for(i = 0; bucket -> status != EMPTY && i < hash -> count; i++)
	{
		if(bucket -> status == OCCUPIED && bucket -> value == value)
			return bucket;
		key = _rehash_func(key, hash -> count);
		bucket = &(hash -> table[key]);
	}

	return NULL;
}

int insert_value(ClosedHash *hash, int value)
{
	int key = _hash_func(value, hash -> count);
	int i;
	Bucket *bucket = &(hash -> table[key]);

	if(search_value(hash, value))
		return -1;

	for(i = 0; i < hash -> count; i++)
	{
		if(bucket -> status == EMPTY || bucket -> status == DELETED)
		{
			bucket -> value = value;
			bucket -> status = OCCUPIED;
			return 0;
		}	
		key = _rehash_func(key, hash -> count);
		bucket = &(hash -> table[key]);
	}
	
	return 1;
}

int delete_value(ClosedHash *hash, int value)
{
	Bucket *bucket = search_value(hash, value);
	if(bucket == NULL)
		return -1;
	bucket -> status = DELETED;
	
	return 0;
}

void dump_table(ClosedHash *hash)
{
	int i;
	for(i = 0; i < hash -> count; i++)
	{
		printf("%02d: ", i);
		switch(hash -> table[i].status)
		{
			case OCCUPIED:
				printf("%d\n", hash -> table[i].value);
				break;
			case EMPTY:
				puts("--- Value unregistered ---");
				break;
			case DELETED:
				puts("--- Value deleted ---");
				break;
		}
	}
}

void destroy_table(ClosedHash *hash)
{
	int i;
	for(i = 0; i < hash -> count; i++)
		hash -> table[i].status = EMPTY;
	free(hash -> table);
	hash -> count = 0;
}

int main(int argc, char *argv[])
{
	ClosedHash hash;
	int count;
	printf("Enter the size of the hash table:");
	scanf("%d", &count);

	initialize_table(&hash, count);	

	char cmd[15];
	int value;	
	Bucket *bucket;
	
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "insert"))
		{
			printf("Insert value: ");
			scanf("%d", &value);
			if(insert_value(&hash, value) == -1)
				printf("Value %d already in the hash table", value);
			else if(insert_value(&hash, value) == 1)
				printf("The hash table is full\n");
		}	
		else if(!strcmp(cmd, "search"))
		{
			printf("Search value: ");
			scanf("%d", &value);
			bucket = search_value(&hash, value);

			if(bucket != NULL)
				printf("Value %d found\n", value);
			else
				printf("Value %d not found\n", value);
		}
		else if(!strcmp(cmd, "delete"))
		{
			printf("Delete value: ");
			scanf("%d", &value);
			
			if(delete_value(&hash, value) == 0)
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
