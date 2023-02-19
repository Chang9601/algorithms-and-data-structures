#include <stdbool.h>

typedef struct _Queue {
	int count;
	int idx;
	int front; 
	int rear; 
	int *pointer;	
} Queue;

void initQueue(Queue *queue, int count);
int pushQueue(Queue *queue, int value);
int popQueue(Queue *queue, int *value);
int frontQueue(Queue *queue, int *value);
int backQueue(Queue *queue, int *value);
bool isEmptyQueue(Queue *queue);
void destroyQueue(Queue *queue);
