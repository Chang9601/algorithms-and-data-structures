#include <stdio.h>
#include <stdbool.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX_VERTEX 100
#define INF 20000000

typedef struct _AdjacencyMatrix {
	int weight[MAX_VERTEX + 1][MAX_VERTEX + 1];
	int num_vertices;
} AdjacencyMatrix;

void initialize_matrix(AdjacencyMatrix *matrix)
{
	int i, j;
	
	matrix -> num_vertices = 0;
	for(i = 1; i <= MAX_VERTEX; i++)
	{
		for(j = 1; j <= MAX_VERTEX; j++)
		{
			if(i == j)
				matrix -> weight[i][j] = 0;
			else
				matrix -> weight[i][j] = INF;
		}
	}
}

void make_matrix(AdjacencyMatrix *matrix, bool directed)
{
	int i;
	int num_edges;
	int vertex, other_vertex, weight;

	initialize_matrix(matrix);
	
	printf("Number of vertices and edges: ");
	scanf("%d %d", &(matrix -> num_vertices), &num_edges);
	for(i = 1; i <= num_edges; i++)
	{
		printf("Edge and weight: ");
		scanf("%d %d %d", &vertex, &other_vertex, &weight);
		matrix -> weight[vertex][other_vertex] = weight;
		if(!directed)
			matrix -> weight[other_vertex][vertex] = weight;
	}
}

void floyd_warshall(AdjacencyMatrix *matrix)
{
	int i, j, k;

	for(k = 1; k <= matrix -> num_vertices; k++)
	{
		for(i = 1; i <= matrix -> num_vertices; i++)
		{
			for(j = 1; j <= matrix -> num_vertices; j++)
			{
				matrix -> weight[i][j] = MIN(matrix -> weight[i][j], matrix -> weight[i][k] + matrix -> weight[k][j]);
			}
		}
	}
}

void print_matrix(AdjacencyMatrix *matrix)
{
	int i, j;

	for(i = 1; i <= matrix -> num_vertices; i++)
	{
		printf("%d: ", i);
		for(j = 1; j <= matrix -> num_vertices; j++)
			printf(" %3d", matrix -> weight[i][j]);
		putchar('\n');
	}
}

int main(int argc, char *argv)
{
	AdjacencyMatrix matrix;

	make_matrix(&matrix, false);
	
	floyd_warshall(&matrix);
	print_matrix(&matrix);

	return 0;
}
