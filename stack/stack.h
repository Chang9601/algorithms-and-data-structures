#include <stdbool.h>

typedef struct _stack {
	int count;
	int top; 
	int *pointer;	
} stack;

void initialize_stack(stack *stk, int count);
int push(stack *stk, int value);
int pop(stack *stk, int *value);
int top(stack *stk, int *value);
bool is_empty_stack(stack *stk);
void destroy_stack(stack *stk);
