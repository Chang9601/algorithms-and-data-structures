#include <stdbool.h>
#define SET_SIZE 100

typedef struct {
	int root[SET_SIZE + 1]; // root element
	int size[SET_SIZE + 1]; // number of elements in subtree i
	int count; // number of elements in set
} UnionFind;

void initialize_union_find(UnionFind *uf, int count);
void unite_sets(UnionFind *uf, int x, int y);
bool is_same_set(UnionFind *uf, int x, int y);
int find_root(UnionFind *uf, int x);
