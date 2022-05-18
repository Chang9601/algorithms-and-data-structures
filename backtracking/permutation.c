#include <stdio.h>
#include <stdbool.h>

#define MAX_CANDIDATES 100
#define MAX_SIZE 100

bool finished = false;

bool is_a_solution(int array[], int count, int size)
{
	return count == size;
}

void process_solution(int array[], int count, int input)
{
	int i;

	for(i = 1; i <= count; i++) 
		printf(" %d", a[i]);
	putchar('\n');
}

void construct_candidates(int array[], int count, int size, int candidates[], int *next_candidate_position)
{
	int i;
	bool is_in_permutation[MAX_SIZE];

	for(i = 1; i < MAX_SIZE; i++)
		is_in_permutation[i] = false;
	
	for(i = 1; i < count; i++)
		is_in_permutation[array[i]] = true;

	*next_candidate_position = 0;

	for(i = 1; i <= size; i++)
		if(!is_in_permutation[i])
		{
			candidates[*next_candidate_position] = i;
			*next_candidate_position++;
		}	
}

void backtrack(int array[], int count, int input)
{
	int candidates[MAX_CANDIDATES];
	int next_candidate_position;
	int i;

	if(is_a_solution(array, count, input))
		process_solution(array, count, input);
	else
	{
		count++;
		construct_candidates(array, count, input, candidates, &next_candidate_position);
		for(i = 0; i < next_candidate_position; i++)
		{
			array[count] = candidates[i];
			make_move(array, count, input);
			backtrack(array, count, input);
			unmake_move(array, count, input);
		}	

		if(finished)
			return;
	}
}

int main(void)
{
	int array[MAX_SIZE];
	backtrack(array, 0, 5);

	return 0;
}
