#include <stdio.h>
#define SWAP(a,b) do{int t = a; a = b; b = t;}while(0)

void bubble_sort(int array[], int array_size)
{
	int i,j;

	for(i = 0; i < array_size - 1; i++)
	{
		for(j = array_size - 1; j > i; j--)
		{
			if(array[j - 1] > array[j])
				SWAP(array[j - 1], array[j]);
		}
	}
}

int main(int argc, char *argv[])
{
	int array[] = {5, 7, 1, 3, 8, 8, 9, 1, 2};
	int array_size = sizeof(array) / sizeof(array[0]);
	
	bubble_sort(array, array_size);
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	putchar('\n');
	return 0;
}
