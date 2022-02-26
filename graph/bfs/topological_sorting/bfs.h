#ifndef BFS_HEADER
#define BFS_HEADER

#include "queue.h"
#include "graph.h"

typedef enum _Status {
	UNDISCOVERED, DISCOVERED, PROCESSED
} Status;

void initialize_bfs(Graph *graph);
void bfs(Graph *graph, int start_vertex);
void find_path(int start_vertex, int end_vertex, int parent_vertex[]);

#endif
