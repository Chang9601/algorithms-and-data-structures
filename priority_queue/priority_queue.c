#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "priority_queue.h"

static bool _is_empty_priority_queue(PriorityQueue *pq)
{
	return pq -> count <= 0;
}

static int _find_parent_index(int index)
{
	if(index == 1)
		return -1;

	return index / 2;
}

static int _find_child_index(int index)
{
	return index * 2;
}

static void _swap_priority_queue(PriorityQueue *pq, int i, int j)
{
	int tmp;
	tmp = pq -> pq[i];
	pq -> pq[i] = pq -> pq[j];
	pq -> pq[j] = tmp;
}

static void _bubble_up(PriorityQueue *pq, int idx)
{
	if(_find_parent_index(idx) == -1)
		return;
	if(pq -> pq[_find_parent_index(idx)] > pq -> pq[idx])
	{
		_swap_priority_queue(pq, idx, _find_parent_index(idx));
		_bubble_up(pq, _find_parent_index(idx));
	}
}

static void _bubble_down(PriorityQueue *pq, int idx)
{
	int child_index = _find_child_index(idx);
	int min_index = idx;
	int i;

	for(i = 0; i <= 1; i++)
	{
		if(child_index + i <= pq -> count)
		{
			if(pq -> pq[min_index] > pq -> pq[child_index + i])
				min_index = child_index + i;	
		}
	}

	if(min_index != idx)
	{
		_swap_priority_queue(pq, idx, min_index);
		_bubble_down(pq, min_index);
	}
}

void initialize_priority_queue(PriorityQueue *pq)
{
	pq -> count = 0;
}

void insert_priority_queue(PriorityQueue *pq, int value)
{
	if(pq -> count >= MAX)
		puts("Warning: priority queue overflow");
	else
	{
		pq -> count++;
		pq -> pq[pq -> count] = value;
		_bubble_up(pq, pq -> count);
	}
} 

int delete_priority_queue(PriorityQueue *pq)
{
	int min_value = -1;

	if(!_is_empty_priority_queue(pq))
	{
		min_value = pq -> pq[1];
		pq -> pq[1] = pq -> pq[pq -> count];
		pq -> count--;
		_bubble_down(pq, 1);
	}

	return min_value;
}

int main(int argc, char *argv[])
{
	char cmd[15];
	int value;
	PriorityQueue pq;
	initialize_priority_queue(&pq);

	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "insert"))
		{
			printf("Insert value: ");
			scanf("%d", &value);
			insert_priority_queue(&pq, value);
		}
		else if(!strcmp(cmd, "delete"))
		{
			int result = delete_priority_queue(&pq);
		
			if(result == -1)
				puts("Empty priority queue");
			else
				printf("Value %d deleted\n", result);
		}	
		else
			puts("Invalid command");
	}

	return 0;
}
