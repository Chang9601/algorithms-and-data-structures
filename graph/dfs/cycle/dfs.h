#ifndef DFS_HEADER
#define DFS_HEADER

#include "graph.h"

typedef enum _Status {
	UNDISCOVERED, DISCOVERED, PROCESSED
} Status;

void initialize_dfs(Graph *graph);
void dfs(Graph *graph, int start_vertex);
void find_path(int start_vertex, int end_vertex, int parent_vertex[]);
void process_edge(int vertex, int other_vertex);
#endif
