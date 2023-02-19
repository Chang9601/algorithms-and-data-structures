#include <stdbool.h>

typedef struct _Stack {
	int count;
	int top; 
	int *pointer;	
} Stack;

void initStack(Stack *stack, int count);
int pushStack(Stack *stack, int value);
int popStack(Stack *stack, int *value);
int topStack(Stack *stack, int *value);
bool isEmptyStack(Stack *stack);
void destroyStack(Stack *stack);
