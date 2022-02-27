#include <stdbool.h>

typedef struct _Stack {
	int count;
	int top; 
	int *pointer;	
} Stack;

void initialize_stack(Stack *stack, int count);
int push_stack(Stack *stack, int value);
int pop_stack(Stack *stack, int *value);
int top_stack(Stack *stack, int *value);
bool is_empty_stack(Stack *stack);
void destroy_stack(Stack *stack);
