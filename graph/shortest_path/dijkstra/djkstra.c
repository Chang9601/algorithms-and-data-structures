#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

#define INF 2000000000
int parent_vertex[MAX_VERTEX + 1];

int* dijkstra(Graph *graph, int start_vertex)
{
	int i;
	Edge *edge;
	bool in_tree[MAX_VERTEX + 1];
	int *distance = calloc(MAX_VERTEX + 1, sizeof(int));
	int vertex, other_vertex;
	int min_distance;

	for(i = 1; i <= graph -> num_vertices; i++)
	{
		distance[i] = INF;	
		in_tree[i] = false;
		parent_vertex[i] = -1;
	}

	distance[start_vertex] = 0;
	vertex = start_vertex;

	while(!in_tree[vertex])
	{
		in_tree[vertex] = true;
		
		if(vertex != start_vertex)
			printf("Edge (%d, %d) in tree\n", parent_vertex[vertex], vertex);
		
		for(edge = graph -> edges[vertex]; edge; edge = edge -> next)
		{
			other_vertex = edge -> other_vertex;
			if(distance[other_vertex] > distance[vertex] + edge -> weight)
			{
				distance[other_vertex] = distance[vertex] + edge -> weight;
				parent_vertex[other_vertex] = vertex;
			}
			
		}
		
		min_distance = INF;
		for(i = 1; i <= graph -> num_vertices; i++)
		{
			if(!in_tree[i] && (min_distance > distance[i]))
			{
				min_distance = distance[i];
				vertex = i;
			}
		}
	}

	return distance;	
}

int main(int argc, char *argv[])
{
	Graph graph;
	bool directed = false;
	int weight;
	int i;
	
	make_graph(&graph, directed);
	int *distance = dijkstra(&graph, 1);
	
	for(i = 1; i <= graph.num_vertices; i++)
		printf("Shortest distance from 1 to %d: %d\n", i, distance[i]);

	destroy_graph(&graph);
	free(distance);
	distance = NULL;

	return 0;
}
