#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void initStack(Stack *stack, int count)
{
	stack -> pointer = calloc(count, sizeof(int));
	stack -> count = count;
	stack -> top = 0;
}

int pushStack(Stack *stack, int value)
{
	if(stack -> top >= stack -> count)
		return -1;
	stack -> pointer[(stack -> top)++] = value;
	return 0;
}

int popStack(Stack *stack, int *value)
{
	if(stack -> top <= 0)
		return -1;
	*value = stack -> pointer[--(stack -> top)];
	return 0;
}

int topStack(Stack *stack, int *value)
{
	if(stack -> top <= 0)
		return -1;
	*value = stack -> pointer[(stack -> top) - 1];
	return 0;
}
	
bool isEmptyStack(Stack *stack)
{
	return stack -> top <= 0;
}	

void destroyStack(Stack *stack)
{
	if(stack -> pointer)
		free(stack -> pointer);
	stack -> top = stack -> count = 0;
	stack -> pointer = NULL;
}

int main(int argc, char *argv[])
{
	char cmd[15];
	Stack stack;
	int count;
	int value;
	printf("Enter the size of a stack: ");
	scanf("%d", &count);

	initStack(&stack, count);
		
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "push"))
		{
			printf("Push value: ");
			scanf("%d", &value);
			if(pushStack(&stack, value) != 0)
				puts("Capacity exceeded ");
		}	
		else if(!strcmp(cmd, "pop"))
		{
			if(isEmptyStack(&stack))
				puts("Empty stack");
			else
			{
				popStack(&stack, &value);
				printf("Value %d deleted\n", value);
			}
		}
		else if(!strcmp(cmd, "top"))
		{
			if(isEmptyStack(&stack))
				puts("Empty stack");
			else
			{	topStack(&stack, &value);
				printf("Value %d at the top\n", value);
			}
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the stack");
			destroyStack(&stack);
		}
		else
			puts("Wrong command");
	}
	
	return 0;
}
