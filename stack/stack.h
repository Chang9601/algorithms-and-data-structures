#include <stdbool.h>

typedef struct _Stack {
	int count;
	int top; 
	int *pointer;	
} Stack;

void initialize_stack(Stack *stack, int count);
int push(Stack *stack, int value);
int pop(Stack *stack, int *value);
int top(Stack *stack, int *value);
bool is_empty_stack(Stack *stack);
void destroy_stack(Stack *stack);
