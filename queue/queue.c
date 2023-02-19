#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

void initQueue(Queue *queue, int count)
{
	queue -> pointer = calloc(count, sizeof(int));
	queue -> count = count;
	queue -> idx = queue -> front = queue -> rear = 0;
}

int pushQueue(Queue *queue, int value)
{
	if(queue -> idx >= queue -> count)
		return -1;
	queue -> idx++; 
	queue -> pointer[(queue -> rear)++] = value;
	queue -> rear %= queue -> count;

	return 0;
}

int popQueue(Queue *queue, int *value)
{
	if(queue -> idx <= 0)
		return -1;
	queue -> idx--;
	*value = queue -> pointer[(queue -> front)++];
	queue -> front %= queue -> count;

	return 0;
}

int frontQueue(Queue *queue, int *value)
{
	if(queue -> idx <= 0)
		return -1;
	*value = queue -> pointer[(queue -> front)];

	return 0;
}
	
int backQueue(Queue *queue, int *value)
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

bool isEmptyQueue(Queue *queue)
{
	return queue -> idx <= 0;
}	

void destroyQueue(Queue *queue)
{
	if(queue -> pointer)
		free(queue -> pointer);
	queue -> idx = queue -> front = queue -> rear = 0;
	queue -> pointer = NULL;
}

int main(int argc, char *argv[])
{
	char cmd[15];
	Queue queue;
	int count;
	int value;
	printf("Enter the size of a queue: ");
	scanf("%d", &count);

	initQueue(&queue, count);
		
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "push"))
		{
			printf("Push value: ");
			scanf("%d", &value);
			if(pushQueue(&queue, value) != 0)
				puts("Capacity exceeded ");
		}	
		else if(!strcmp(cmd, "pop"))
		{
			if(isEmptyQueue(&queue))
				puts("Empty queue");
			else
			{
				popQueue(&queue, &value);
				printf("Value %d deleted\n", value);
			}
		}
		else if(!strcmp(cmd, "front"))
		{
			if(isEmptyQueue(&queue))
				puts("Empty queue");
			else
			{	
				frontQueue(&queue, &value);
				printf("Value %d at the front\n", value);
			}
		}
		else if(!strcmp(cmd, "back"))
		{
			if(isEmptyQueue(&queue))
				puts("Empty queue");
			else
			{	
				backQueue(&queue, &value);
				printf("Value %d at the rear\n", value);
			}
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the queue");
			destroyQueue(&queue);
		}
		else
			puts("Wrong command");
	}
	
	return 0;
}
