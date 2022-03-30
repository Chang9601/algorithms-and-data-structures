#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "union_find.h"

typedef struct _EdgePair {
	int vertex, other_vertex;
	int weight;
} EdgePair;

static void to_edge_array(Graph *graph, EdgePair edge_pair[])
{
	int i, j;
	Edge *edge;
	
	j = 0;
	for(i = 1; i <= graph -> num_vertices; i++)
	{
		for(edge = graph -> edges[i]; edge; edge = edge -> next)
		{
			if(edge -> other_vertex > i)
			{
				edge_pair[j].vertex = i;
				edge_pair[j].other_vertex = edge -> other_vertex;
				edge_pair[j].weight = edge -> weight;
				j++;
			}
		}
	}
}

static int compare_weight(const void *vertex, const void *other_vertex)
{
	EdgePair *_vertex = (EdgePair *)vertex;
	EdgePair *_other_vertex = (EdgePair *)other_vertex;

	if(_vertex -> weight < _other_vertex -> weight)
		return -1;
	else if(_vertex -> weight > _other_vertex -> weight)
		return 1;
	else
		return 0;
}

int kruskal(Graph *graph)
{
	int i;
	UnionFind uf;
	EdgePair edge_pair[MAX_VERTEX + 1];
	int weight = 0;

	initialize_union_find(&uf, graph -> num_vertices);
	to_edge_array(graph, edge_pair);
	qsort(&edge_pair, graph -> num_edges, sizeof(EdgePair), &compare_weight);
	
	for(i = 0; i < graph -> num_edges; i++)
	{
		if(!is_same_set(&uf, edge_pair[i].vertex, edge_pair[i].other_vertex))
		{
			printf("Edge (%d, %d) in MST\n", edge_pair[i].vertex, edge_pair[i].other_vertex);
			weight += edge_pair[i].weight;
			unite_sets(&uf, edge_pair[i].vertex, edge_pair[i].other_vertex);
		}
	}

	return weight;
}

int main(int argc, char *argv[])
{
	Graph graph;
	bool directed = false;
	int weight;

	make_graph(&graph, directed);
	weight = kruskal(&graph);

	printf("Weight: %d\n", weight);	

	destroy_graph(&graph);

	return 0;
}

