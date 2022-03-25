#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define MAX_INT 2000000000
int parent_vertex[MAX_VERTEX + 1];

int prim(Graph *graph, int start_vertex)
{
	int i;
	Edge *edge;
	bool in_tree[MAX_VERTEX + 1];
	int weights[MAX_VERTEX + 1];
	int vertex, other_vertex;
	int min_weight;
	int total_weight;

	for(i = 1; i <= graph -> num_vertices; i++)
	{
		in_tree[i] = false;
		weights[i]= MAX_INT;
		parent_vertex[i] = -1;
	}	

	total_weight = 0;
	weights[start_vertex] = 0;
	vertex = start_vertex;

	while(!in_tree[vertex])
	{
		in_tree[vertex] = true;
		if(vertex != start_vertex)
		{
			printf("Edge (%d, %d) in tree\n", parent_vertex[vertex], vertex);
			total_weight += min_weight;
		}

		for(edge = graph -> edges[vertex]; edge; edge = edge -> next)
		{
			other_vertex = edge -> other_vertex;
			if((weights[other_vertex] > edge -> weight) && (!in_tree[other_vertex])) 
			{
				weights[other_vertex] = edge -> weight;
				parent_vertex[other_vertex] = vertex;
			}
		}

		min_weight = MAX_INT;	
		for(i = 1; i <= graph -> num_vertices; i++)
		{
			if((!in_tree[i]) && (min_weight > weights[i]))
			{
				min_weight = weights[i];
				vertex = i;
			}
		}
	}

	return total_weight;
}


int main(int argc, char *argv[])
{
	Graph graph;
	bool directed = false;
	int weight;

	make_graph(&graph, directed);
	weight = prim(&graph, 1);

	printf("Weight: %d\n", weight);	

	destroy_graph(&graph);

	return 0;
}
