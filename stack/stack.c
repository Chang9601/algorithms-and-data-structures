#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

void initialize_stack(Stack *stack, int count)
{
	stack -> pointer = malloc(sizeof(int) * count);
	stack -> count = count;
	stack -> top = 0;
}

int push_stack(Stack *stack, int value)
{
	if(stack -> top >= stack -> count)
		return -1;
	stack -> pointer[(stack -> top)++] = value;
	return 0;
}

int pop_stack(Stack *stack, int *value)
{
	if(stack -> top <= 0)
		return -1;
	*value = stack -> pointer[--(stack -> top)];
	return 0;
}

int top_stack(Stack *stack, int *value)
{
	if(stack -> top <= 0)
		return -1;
	*value = stack -> pointer[(stack -> top) - 1];
	return 0;
}
	
bool is_empty_stack(Stack *stack)
{
	return stack -> top <= 0;
}	

void destroy_stack(Stack *stack)
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

	initialize_stack(&stack, count);
		
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "push"))
		{
			printf("Push value: ");
			scanf("%d", &value);
			if(push_stack(&stack, value) != 0)
				puts("Exceeded capacity");
		}	
		else if(!strcmp(cmd, "pop"))
		{
			if(is_empty_stack(&stack))
				puts("Empty stack");
			else
			{
				pop_stack(&stack, &value);
				printf("Value %d deleted\n", value);
			}
		}
		else if(!strcmp(cmd, "top"))
		{
			if(is_empty_stack(&stack))
				puts("Empty stack");
			else
			{	top_stack(&stack, &value);
				printf("Value %d at the top\n", value);
			}
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the stack");
			destroy_stack(&stack);
		}
		else
			puts("Wrong command");
	}
	
	return 0;
}
