#include <stdio.h>
#include <stdbool.h>
#include "bfs.h"

extern Status vertex_status[MAX_VERTEX + 1];
extern int parent_vertex[MAX_VERTEX + 1];

int connected_component(Graph *graph)
{
	int i;
	int component_num;
	initialize_bfs(graph);
	
	component_num = 0;	
	for(i = 1; i <= graph -> num_vertices; i++)
	{
		if(vertex_status[i] == UNDISCOVERED)
		{
			bfs(graph, i);
			component_num++;
		}
	}
	return component_num;
}

int main(int argc, char *argv[])
{
	Graph graph;
	bool directed = false;
	int component_num;

	make_graph(&graph, directed);
	component_num = connected_component(&graph);
	printf("Number of components: %d\n", component_num);
	destroy_graph(&graph);
	
	return 0;
}
