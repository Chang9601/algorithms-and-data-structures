#include <stdio.h>
#include "union_find.h"

void initialize_union_find(UnionFind *uf, int count)
{
	uf -> count = count;

	int i;
	for(i = 1; i <= uf -> count; i++)
	{
		uf -> root[i] = i;
		uf -> size[i] = 1;
	}
}

int find_root(UnionFind *uf, int x)
{
	if(x == uf -> root[x])
		return x;
	return uf -> root[x] = find_root(uf, uf -> root[x]);
}

void unite_sets(UnionFind *uf, int x, int y)
{
	// roots of x and y
	int root_x, root_y;

	root_x = find_root(uf, x);
	root_y = find_root(uf, y);	
	
	// x and y in the same set	
	if(root_x == root_y)
		return; 
	
	if(uf -> size[root_x] >= uf -> size[root_y])
	{
		uf -> size[root_x] += uf -> size[root_y];
		uf -> root[root_y] = root_x;
	}
	else
	{
		uf -> size[root_y] += uf -> size[root_x];
		uf -> root[root_x] = root_y;
	}
}

bool is_same_set(UnionFind *uf, int x, int y)
{
	return find_root(uf, x) == find_root(uf, y);
}
