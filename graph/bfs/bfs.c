#include <stdio.h>
#include <stdbool.h>
#include "bfs.h"

Status vertex_status[MAX_VERTEX + 1];
int parent_vertex[MAX_VERTEX + 1];

void initialize_bfs(Graph *graph)
{
	int i;

	for(i = 1; i <= graph -> num_vertices; i++)
	{
		vertex_status[i] = UNDISCOVERED;
		parent_vertex[i] = -1;
	}
}

void bfs(Graph *graph, int start_vertex)
{
	Queue queue;
	ENode *edge;
	int vertex, other_vertex;
	
	initialize_queue(&queue, MAX_VERTEX);
	push_queue(&queue, start_vertex);
	vertex_status[start_vertex] = DISCOVERED;

	while(!is_empty_queue(&queue))
	{
		pop_queue(&queue, &vertex);
		vertex_status[vertex] = PROCESSED;

		for(edge = graph -> edges[vertex]; edge; edge = edge -> next)
		{
			other_vertex = edge -> other_vertex;
			if(vertex_status[other_vertex] == UNDISCOVERED)
			{
				vertex_status[other_vertex] = DISCOVERED;
				parent_vertex[other_vertex] = vertex;	
				push_queue(&queue, other_vertex);
			}
		}
	}			
	destroy_queue(&queue);
}

void find_path(int start_vertex, int end_vertex, int parent_vertex[])
{
	if(start_vertex == end_vertex || end_vertex == -1)
		printf("%d ", start_vertex);
	else
	{
		find_path(start_vertex, parent_vertex[end_vertex], parent_vertex);
		printf("%d ", end_vertex);
	}
}

int main(int argc, char *argv[])
{
	Graph graph;
	bool directed = false;
	int i;

	make_graph(&graph, directed);
	bfs(&graph, 1);

	for(i = 1; i <= graph.num_vertices; i++)
	{
		find_path(1, i, parent_vertex);
		putchar('\n');
	}
	destroy_graph(&graph);
	
	return 0;
}
