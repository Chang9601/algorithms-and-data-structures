#include <stdio.h>

typedef enum _Color {
	BLACK, WHITE, UNCOLORED
} Color;

Status vertex_status[MAX_VERTEX + 1];

void bipartie(Graph *graph)
{
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
