#include <stdio.h>
#include <stdlib.h>

static void _merge(int array[], int *buffer, int low, int high)
{
	if(low >= high)
		return;
	
	int mid = low + (high - low) / 2;
	_merge(array, buffer, low, mid);
	_merge(array, buffer, mid + 1, high);

	int i, j, k, pos;
	j = k = 0;
	pos = low;

	for(i = low; i <= mid; i++)
		buffer[j++] = array[i];
	while(k < j && i <= high)
		array[pos++] = (buffer[k] <= array[i]) ? buffer[k++] : array[i++];
	while(k < j)
		array[pos++] = buffer[k++];	
}

void merge_sort(int array[], int *buffer, int array_size)
{
	buffer = malloc(sizeof(array[0]) * array_size);
	_merge(array, buffer, 0, array_size - 1);
	free(buffer);
}

int main(int argc, char *argv[])
{
	int array[] = {5, 7, 1, 3, 8, 8, 9, 1, 2};
	int array_size = sizeof(array) / sizeof(array[0]);
	int *buffer;

	merge_sort(array, buffer, array_size);
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	putchar('\n');

	return 0;
}	
