#include <stdbool.h>

typedef struct _queue {
	int count;
	int idx;
	int front; 
	int rear; 
	int *pointer;	
} queue;

void initialize_queue(queue *que, int count);
int push(queue *que, int value);
int pop(queue *que, int *value);
int top(queue *que, int *value);
bool is_empty_queue(queue *que);
void destroy_queue(queue *que);
