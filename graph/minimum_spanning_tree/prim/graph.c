#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"

static Edge *_allocate_node(void)
{
	return malloc(sizeof(Edge));
}

void initialize_graph(Graph *graph, bool directed)
{
	int i;
	graph -> num_vertices = 0;
	graph -> num_edges = 0;
	graph -> directed = directed;
	
	for(i = 1; i <= MAX_VERTEX; i++)
	{
		graph -> degrees[i] = 0;
		graph -> edges[i] = NULL;
	}
}

void insert_edge(Graph *graph, int vertex, int other_vertex, int weight, bool directed)
{
	Edge *edge = _allocate_node();
	
	edge -> other_vertex = other_vertex;
	edge -> weight = weight;
	edge -> next = graph -> edges[vertex];
	graph -> edges[vertex] = edge;
	graph -> degrees[vertex]++;
	
	if(!directed)
		insert_edge(graph, other_vertex, vertex, weight, true);
	else
		graph -> num_edges++;	
} 

void delete_edge(Graph *graph, int vertex, int other_vertex, bool directed)
{
	// TO-DO: Use double pointer to delete an edge
	Edge *curr_edge, *prev_edge;
	
	prev_edge = NULL;	
	for(curr_edge = graph -> edges[vertex]; curr_edge; prev_edge = curr_edge, curr_edge = curr_edge -> next)
	{
		if(curr_edge -> other_vertex == other_vertex)
		{
			graph -> degrees[vertex]--;

			if(prev_edge)
				prev_edge -> next = curr_edge -> next;
			else
				graph -> edges[vertex] = curr_edge -> next;
			free(curr_edge);

			if(!directed)
				delete_edge(graph, other_vertex, vertex, true);
			else
				graph -> num_edges--;
			return;
		} 	
	}
	printf("Edge (%d, %d) not found in the graph.\n", vertex, other_vertex);	
}

void make_graph(Graph *graph, bool directed)
{
	int i;
	int vertex, other_vertex;
	int weight;
	int num_edges;

	initialize_graph(graph, directed);
	printf("Number of vertices and edges: ");
	scanf("%d %d", &(graph -> num_vertices), &num_edges);
	
	for(i = 1; i <= num_edges; i++)
	{
		printf("Edge and weight: ");
		scanf("%d %d %d", &vertex, &other_vertex, &weight);
		insert_edge(graph, vertex, other_vertex, weight, directed);
	}
}	

void print_graph(Graph *graph)
{
	int i;
	Edge *edge;
	for(i = 1; i <= graph -> num_vertices; i++)
	{
		printf("Vertex %d: ", i);
		for(edge = graph -> edges[i]; edge; edge = edge -> next)
			printf("%d ", edge -> other_vertex);	
		putchar('\n');
	}
}

void destroy_graph(Graph *graph)
{
	int i;
	Edge *curr_edge, *next_edge;
	
	for(i = 1; i <= graph -> num_vertices; i++)
	{
		curr_edge = graph -> edges[i];
		while(curr_edge)
		{
			next_edge = curr_edge -> next;
			free(curr_edge);
			curr_edge = next_edge;	
		}
		graph -> edges[i] = NULL;
	}
}
