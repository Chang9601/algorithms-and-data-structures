#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "graph.h"

void calculate_indegrees(Graph *graph, int indegrees[])
{
	int i;
	Edge *edge;

	for(i = 1; i <= graph -> num_vertices; i++)
		indegrees[i] = 0;
	for(i = 1; i <= graph -> num_vertices; i++)
		for(edge = graph -> edges[i]; edge; edge = edge -> next)
			indegrees[edge -> other_vertex]++;
}
		
void topological_sorting(Graph *graph, int sorted_array[])
{
	int indegrees[MAX_VERTEX + 1];
	Queue queue;
	int vertex, other_vertex;
	Edge *edge;
	int i, j;

	calculate_indegrees(graph, indegrees);
	initialize_queue(&queue, MAX_VERTEX);

	for(i = 1; i <= graph -> num_vertices; i++)
	{
		if(!indegrees[i])
			push_queue(&queue, i);
	}

	j = 0;
	while(!is_empty_queue(&queue))
	{
		pop_queue(&queue, &vertex);
		sorted_array[++j] = vertex;

		for(edge = graph -> edges[vertex]; edge; edge = edge -> next)
		{
			other_vertex = edge -> other_vertex;
			indegrees[other_vertex]--;
	
			if(!indegrees[other_vertex])
				push_queue(&queue, other_vertex);
		}
	}
	
	destroy_queue(&queue);
	if(j != graph -> num_vertices)
		printf("Not a DAG: %d vertices found.\n", j);
}

int main(void)
{
	Graph graph;
	bool directed = true;
	int sorted_array[MAX_VERTEX + 1];
	int i;

	make_graph(&graph, directed);
	print_graph(&graph);

	topological_sorting(&graph, sorted_array);
	for(i = 1; i <= graph.num_vertices; i++)
		printf("%d%s", sorted_array[i], i == graph.num_vertices ? "" : " ");
	putchar('\n');
	destroy_graph(&graph);
}
