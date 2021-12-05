#include <stdio.h>
#define SWAP(a,b) do{int t = a; a = b; b = t;}while(0)

void selection_sort(int array[], int array_size)
{
	int i,j;
	int min_index;

	for(i = 0; i < array_size; i++)
	{
		min_index = i;
		for(j = i + 1; j < array_size; j++)
			if(array[min_index] > array[j])
				min_index = j;
		SWAP(array[i], array[min_index]);
	}
}

int main(int argc, char *argv[])
{
	int array[] = {5, 7, 1, 3, 8, 8, 9, 1, 2};
	int array_size = sizeof(array) / sizeof(array[0]);
	
	selection_sort(array, array_size);
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	putchar('\n');
	return 0;
}
