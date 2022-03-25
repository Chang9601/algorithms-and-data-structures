#define MAX 100
typedef struct {
	int pq[MAX + 1];
	int count;
} PriorityQueue;

void initialize_priority_queue(PriorityQueue *pq);
void insert_priority_queue(PriorityQueue *pq, int value);
int delete_priority_queue(PriorityQueue *pq);
