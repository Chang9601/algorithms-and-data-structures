#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stdbool.h>

typedef struct _Queue {
	int count;
	int idx;
	int front; 
	int rear; 
	int *pointer;	
} Queue;

void initialize_queue(Queue *queue, int count);
int push_queue(Queue *queue, int value);
int pop_queue(Queue *queue, int *value);
int front_queue(Queue *queue, int *value);
int back_queue(Queue *queue, int *value);
bool is_empty_queue(Queue *queue);
void destroy_queue(Queue *queue);

#endif
