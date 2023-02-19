#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "graph.h"

static Edge *_allocNode(void);

void initGraph(Graph *graph, bool directed)
{
	int i;
	graph -> numVertices = 0;
	graph -> numEdges = 0;
	graph -> directed = directed;
	
	for(i = 1; i <= MAX_VERTEX; i++)
	{
		graph -> degrees[i] = 0;
		graph -> edges[i] = NULL;
	}
}

void insertEdge(Graph *graph, int vertex, int otherVertex, bool directed)
{
	Edge *edge = _allocNode();
	
	edge -> otherVertex = otherVertex;
	edge -> weight = 0;
	edge -> next = graph -> edges[vertex];
	graph -> edges[vertex] = edge;
	graph -> degrees[vertex]++;
	
	if(!directed)
		insertEdge(graph, otherVertex, vertex, true);
	else
		graph -> numEdges++;	
} 

void removeEdge(Graph *graph, int vertex, int otherVertex, bool directed)
{
	// TO-DO: Use double pointer to remove an edge
	Edge *curr, *prev;
	
	prev = NULL;	
	for(curr = graph -> edges[vertex]; curr; prev = curr, curr = curr -> next)
	{
		if(curr -> otherVertex == otherVertex)
		{
			graph -> degrees[vertex]--;

			if(prev)
				prev -> next = curr -> next;
			else
				graph -> edges[vertex] = curr -> next;
			free(curr);

			if(!directed)
				removeEdge(graph, otherVertex, vertex, true);
			else
				graph -> numEdges--;
			return;
		} 	
	}
	printf("Edge (%d, %d) not found in the graph.\n", vertex, otherVertex);	
}

void makeGraph(Graph *graph, bool directed)
{
	int i;
	int vertex, otherVertex;
	int numEdges;

	initGraph(graph, directed);
	printf("Number of vertices and edges: ");
	scanf("%d %d", &(graph -> numVertices), &numEdges);
	
	for(i = 1; i <= numEdges; i++)
	{
		printf("Edge: ");
		scanf("%d %d", &vertex, &otherVertex);
		insertEdge(graph, vertex, otherVertex, directed);
	}
}	

void printGraph(Graph *graph)
{
	int i;
	Edge *edge;
	for(i = 1; i <= graph -> numVertices; i++)
	{
		printf("Vertex %d: ", i);
		for(edge = graph -> edges[i]; edge; edge = edge -> next)
			printf("%d ", edge -> otherVertex);	
		putchar('\n');
	}
}

void destroyGraph(Graph *graph)
{
	int i;
	Edge *curr, *next_edge;
	
	for(i = 1; i <= graph -> numVertices; i++)
	{
		curr = graph -> edges[i];
		while(curr)
		{
			next_edge = curr -> next;
			free(curr);
			curr = next_edge;	
		}
		graph -> edges[i] = NULL;
	}
}

int main(int argc, char *argv[])
{
	char cmd[15];
	Graph graph;
	bool directed = false;
	int vertex, otherVertex;

	makeGraph(&graph, directed);
	
	while(scanf("%s", cmd) != EOF)
	{
		if(!strcmp(cmd, "insert"))
		{
			printf("Insert an edge: ");
			scanf("%d %d", &vertex, &otherVertex);
			insertEdge(&graph, vertex, otherVertex, directed);
		}
		else if(!strcmp(cmd, "remove"))
		{
			printf("Delete an edge: " );
			scanf("%d %d", &vertex, &otherVertex);		
			removeEdge(&graph, vertex, otherVertex, directed);
		}
		else if(!strcmp(cmd, "print"))
		{
			puts("Print the graph");
			printGraph(&graph);
		}
		else if(!strcmp(cmd, "destroy"))
		{
			puts("Destroy the graph");
			destroyGraph(&graph);
		}
		else
			puts("Invalud command");	
	}	

	return 0;
}

static Edge *_allocNode(void)
{
	return calloc(1, sizeof(Edge));
}
