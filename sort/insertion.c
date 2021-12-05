#include <stdio.h>
#define SWAP(a,b) do{int t = a; a = b; b = t;}while(0)

void insertion_sort(int array[], int array_size)
{
	int i,j;

	for(i = 1; i < array_size; i++)
	{
		j = i;
		while(j > 0 && array[j - 1] > array[j])
		{
			SWAP(array[j], array[j - 1]);
			j--;
		}
	}
}

int main(int argc, char *argv[])
{
	int array[] = {5, 7, 1, 3, 8, 8, 9, 1, 2};
	int array_size = sizeof(array) / sizeof(array[0]);
	
	insertion_sort(array, array_size);
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	putchar('\n');
	return 0;
}
