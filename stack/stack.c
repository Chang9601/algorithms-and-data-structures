#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void initialize_stack(stack *stk, int count)
{
	stk -> pointer = malloc(sizeof(int) * count);
	stk -> count = count;
	stk -> top = 0;
}

int push(stack *stk, int value)
{
	if(stk -> top >= stk -> count)
		return -1;
	stk -> pointer[(stk -> top)++] = value;
	return 0;
}

int pop(stack *stk, int *value)
{
	if(stk -> top <= 0)
		return -1;
	*value = stk -> pointer[--(stk -> top)];
	return 0;
}

int top(stack *stk, int *value)
{
	if(stk -> top <= 0)
		return -1;
	*value = stk -> pointer[(stk -> top) - 1];
	return 0;
}
	
bool is_empty_stack(stack *stk)
{
	return stk -> top <= 0;
}	

void destroy_stack(stack *stk)
{
	if(stk -> pointer)
		free(stk -> pointer);
	stk -> top = stk -> count = 0;
	stk -> pointer = NULL;
}

int main(int argc, char *argv[])
{
	char cmd[15];
	stack stk;
	int count;
	int value;
	printf("Enter the size of a stack: ");
	scanf("%d", &count);

	initialize_stack(&stk, count);
		
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "push"))
		{
			printf("Push value: ");
			scanf("%d", &value);
			if(push(&stk, value) != 0)
				puts("Exceeded capacity");
		}	
		else if(!strcmp(cmd, "pop"))
		{
			if(is_empty_stack(&stk))
				puts("Empty stack");
			else
			{
				pop(&stk, &value);
				printf("Value %d deleted\n", value);
			}
		}
		else if(!strcmp(cmd, "top"))
		{
			if(is_empty_stack(&stk))
				puts("Empty stack");
			else
			{	top(&stk, &value);
				printf("Value %d at the top\n", value);
			}
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the stack");
			destroy_stack(&stk);
		}
		else
			puts("Wrong command");
	}
	
	return 0;
}
