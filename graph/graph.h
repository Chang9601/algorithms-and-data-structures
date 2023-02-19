#include <stdbool.h>

#define MAX_VERTEX 100

typedef struct _Edge {
	int otherVertex;
	int weight;
	struct _Edge *next;
} Edge;

typedef struct _Graph {
	Edge *edges[MAX_VERTEX + 1];
	int degrees[MAX_VERTEX + 1];
	int numVertices;
	int numEdges;
	bool directed;
} Graph;

void initGraph(Graph *graph, bool directed);
void insertEdge(Graph *graph, int vertex, int otherVertex, bool directed);
void removeEdge(Graph *graph, int vertex, int otherVertex, bool directed);
void makeGraph(Graph *graph, bool directed);
void printGraph(Graph *graph);
void destroyGraph(Graph *graph);


