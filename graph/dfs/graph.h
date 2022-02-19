#include <stdbool.h>

#define MAX_VERTEX 100

typedef struct _Edge {
	int other_vertex;
	int weight;
	struct _Edge *next;
} Edge;

typedef struct _Graph {
	Edge *edges[MAX_VERTEX + 1];
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


