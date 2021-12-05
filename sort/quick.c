#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b) do{int t = a; a = b; b = t;}while(0)

void quick_sort(int array[], int low, int high)
{
	int p_low = low, p_high = high;
	int pivot = array[p_low + (p_high - p_low) / 2];
	
	do
	{
		while(array[p_low] < pivot)
			p_low++;
		while(array[p_high] > pivot)
			p_high--;
		
		if(p_low <= p_high)
		{
			SWAP(array[p_low], array[p_high]);
			p_low++;
			p_high--;
		}
	}while(p_low <= p_high);

	if(low < p_high)
		quick_sort(array, low, p_high);
	if(p_low < high)
		quick_sort(array, p_low, high);
}

int main(int argc, char *argv[])
{
	int array[] = {5, 7, 1, 3, 8, 8, 9, 1, 2};
	int array_size = sizeof(array) / sizeof(array[0]);
	int low = 0;
	int high = array_size - 1; 

	quick_sort(array, low, high);
	for(int i = 0; i < array_size; i++)
		printf("%d ", array[i]);
	putchar('\n');

	return 0;
}	
	
