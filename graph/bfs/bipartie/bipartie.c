#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bfs.h"

#define UNCOLORED 0
#define WHITE 1
#define BLACK 2

bool is_bipartie;
extern Status vertex_status[MAX_VERTEX + 1];
extern int parent_vertex[MAX_VERTEX + 1];
int color[MAX_VERTEX + 1];

int complement_color(int c)
{
	if(c == WHITE)
		return BLACK;
	if(c == BLACK)
		return WHITE;
	return UNCOLORED;
}

void process_edge(int vertex, int other_vertex)
{
	if(color[vertex] == color[other_vertex])
		is_bipartie = false;
	color[other_vertex] = complement_color(color[vertex]);
}

void bipartie(Graph *graph)
{
	is_bipartie = true;
	int i;
	for(i = 1; i <= graph -> num_vertices; i++)
		color[i] = UNCOLORED;

	initialize_bfs(graph);
	for(i = 1; i <= graph -> num_vertices; i++)
	{
		if(vertex_status[i] == UNDISCOVERED)
		{
			color[i] = WHITE;
			bfs(graph, i);
		}
	}
}

int main(int argc, char *argv[])
{
	int i;
	Graph graph;
	bool directed = false;

	make_graph(&graph, directed);
	bipartie(&graph);
	
	for(i = 1; i <= graph.num_vertices; i++)
		printf("%d ", color[i]);
	putchar('\n');

	printf("Graph: %s\n", is_bipartie ? "Bipartie" : "Not bipartie");

	destroy_graph(&graph);
	
	return 0;
}
