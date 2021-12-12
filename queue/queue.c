#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

void initialize_queue(queue *que, int count)
{
	que -> pointer = malloc(sizeof(int) * count);
	que -> count = count;
	que -> idx = que -> front = que -> rear = 0;
}

int push(queue *que, int value)
{
	if(que -> idx >= que -> count)
		return -1;
	que -> idx++; 
	que -> pointer[(que -> rear)++] = value;
	que -> rear %= que -> count;

	return 0;
}

int pop(queue *que, int *value)
{
	if(que -> idx <= 0)
		return -1;
	que -> idx--;
	*value = que -> pointer[(que -> front)++];
	que -> front %= que -> count;

	return 0;
}

int front(queue *que, int *value)
{
	if(que -> idx <= 0)
		return -1;
	*value = que -> pointer[(que -> front)];

	return 0;
}
	
int back(queue *que, int *value)
{
	if(que -> idx <= 0)
		return -1;
	else
	{
		if(que -> rear == 0) *value = que -> pointer[(que -> count) - 1];
		else *value = que -> pointer[(que -> rear) - 1];
	}

	return 0;
}

bool is_empty_queue(queue *que)
{
	return que -> idx <= 0;
}	

void destroy_queue(queue *que)
{
	if(que -> pointer)
		free(que -> pointer);
	que -> idx = que -> front = que -> rear = 0;
	que -> pointer = NULL;
}

int main(int argc, char *argv[])
{
	char cmd[15];
	queue que;
	int count;
	int value;
	printf("Enter the size of a queue: ");
	scanf("%d", &count);

	initialize_queue(&que, count);
		
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "push"))
		{
			printf("Push value: ");
			scanf("%d", &value);
			if(push(&que, value) != 0)
				puts("Exceeded capacity");
		}	
		else if(!strcmp(cmd, "pop"))
		{
			if(is_empty_queue(&que))
				puts("Empty queue");
			else
			{
				pop(&que, &value);
				printf("Value %d deleted\n", value);
			}
		}
		else if(!strcmp(cmd, "front"))
		{
			if(is_empty_queue(&que))
				puts("Empty queue");
			else
			{	front(&que, &value);
				printf("Value %d at the front\n", value);
			}
		}
		else if(!strcmp(cmd, "back"))
		{
			if(is_empty_queue(&que))
				puts("Empty queue");
			else
			{	back(&que, &value);
				printf("Value %d at the rear\n", value);
			}
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the queue");
			destroy_queue(&que);
		}
		else
			puts("Wrong command");
	}
	
	return 0;
}
