#include <stdio.h>
#define SWAP(a,b) do{int t = a; a = b; b = t;}while(0)

static void _heapify(int array[], int low, int high)
{
	int tmp = array[low];
	int parent;
	int child, left_child, right_child;

	for(parent = low; parent < (high + 1) / 2; parent = child)
	{
		left_child = parent * 2 + 1;
		right_child = parent * 2 + 2;
		
		child = (right_child <= high && array[right_child] > array[left_child]) ? right_child : left_child;
		if(tmp >= array[child])
			break;

		array[parent] = array[child];	
	}

	array[parent] = tmp;
}

void heap_sort(int array[], int array_size)
{
	int i;
	for(i = (array_size - 1) / 2; i >= 0; i--)
		_heapify(array, i, array_size - 1);

	for(i = array_size - 1; i > 0; i--)
	{
		SWAP(array[0], array[i]);
		_heapify(array, 0 , i - 1);
	}
}


int main(int argc, char *argv[])
{
	int array[] = {5, 7, 1, 3, 8, 8, 9, 1, 2};
	int array_size = sizeof(array) / sizeof(array[0]);
	int *buffer;

	heap_sort(array, array_size);
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	putchar('\n');

	return 0;
}	
