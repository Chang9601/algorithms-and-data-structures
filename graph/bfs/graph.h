#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <stdbool.h>

#define MAX_VERTEX 100

typedef struct _ENode {
	int other_vertex;
	int weight;
	struct _ENode *next;
} ENode;

typedef struct _Graph {
	ENode *edges[MAX_VERTEX + 1];
	int degrees[MAX_VERTEX + 1];
	int num_vertices;
	int num_edges;
	bool directed;
} Graph;

void initialize_graph(Graph *graph, bool directed);
void insert_edge(Graph *graph, int vertex, int other_vertex, bool directed);
void delete_edge(Graph *graph, int vertex, int other_vertex, bool directed);
void make_graph(Graph *graph, bool directed);
void print_graph(Graph *graph);
void destroy_graph(Graph *graph);

#endif
