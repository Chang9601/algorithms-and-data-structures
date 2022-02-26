#include <stdio.h>
#include "dfs.h"

Status vertex_status[MAX_VERTEX + 1];
int parent_vertex[MAX_VERTEX + 1];
bool finished;

void initialize_dfs(Graph *graph)
{
	int i;
	for(i = 1; i <= graph -> num_vertices; i++)
	{
		vertex_status[i] = UNDISCOVERED;
		parent_vertex[i] = -1;
	}
}

void dfs(Graph *graph, int start_vertex)
{
	if(finished)
		return;

	vertex_status[start_vertex] = DISCOVERED;	
	Edge *edge;
	int other_vertex;

	for(edge = graph -> edges[start_vertex]; edge; edge = edge -> next)
	{
		other_vertex = edge -> other_vertex;
		if(vertex_status[other_vertex] == UNDISCOVERED)
		{
			parent_vertex[other_vertex] = start_vertex;
			process_edge(start_vertex, other_vertex);
			dfs(graph, other_vertex);
		}
		else if(vertex_status[other_vertex] != PROCESSED && (parent_vertex[start_vertex] != other_vertex) || graph -> directed)
			process_edge(start_vertex, other_vertex);
		if(finished)
			return;
	}

	vertex_status[start_vertex] = PROCESSED;	
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

void process_edge(int vertex, int other_vertex)
{
	if(parent_vertex[other_vertex] != vertex)
	{
		printf("Cycle from %d to %d:", other_vertex, vertex);
		find_path(other_vertex, vertex, parent_vertex);
		finished = true;
	}
}


int main(int argc, char *argv[])
{
	Graph graph;
	bool directed = false;
	int i;

	make_graph(&graph, directed);
	dfs(&graph, 1);
	/*
	for(i = 1; i <= graph.num_vertices; i++)
	{
		find_path(1, i, parent_vertex);
		putchar('\n');
	}
	*/
	destroy_graph(&graph);
	return 0;
}
