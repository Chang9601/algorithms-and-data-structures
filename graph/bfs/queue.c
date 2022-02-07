#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

void initialize_queue(Queue *queue, int count)
{
	queue -> pointer = malloc(sizeof(int) * count);
	queue -> count = count;
	queue -> idx = queue -> front = queue -> rear = 0;
}

int push_queue(Queue *queue, int value)
{
	if(queue -> idx >= queue -> count)
		return -1;
	queue -> idx++; 
	queue -> pointer[(queue -> rear)++] = value;
	queue -> rear %= queue -> count;

	return 0;
}

int pop_queue(Queue *queue, int *value)
{
	if(queue -> idx <= 0)
		return -1;
	queue -> idx--;
	*value = queue -> pointer[(queue -> front)++];
	queue -> front %= queue -> count;

	return 0;
}

int front_queue(Queue *queue, int *value)
{
	if(queue -> idx <= 0)
		return -1;
	*value = queue -> pointer[(queue -> front)];

	return 0;
}
	
int back_queue(Queue *queue, int *value)
{
	if(queue -> idx <= 0)
		return -1;
	else
	{
		if(queue -> rear == 0) 
			*value = queue -> pointer[(queue -> count) - 1];
		else
			*value = queue -> pointer[(queue -> rear) - 1];
	}

	return 0;
}

bool is_empty_queue(Queue *queue)
{
	return queue -> idx <= 0;
}	

void destroy_queue(Queue *queue)
{
	if(queue -> pointer)
		free(queue -> pointer);
	queue -> idx = queue -> front = queue -> rear = 0;
	queue -> pointer = NULL;
}

