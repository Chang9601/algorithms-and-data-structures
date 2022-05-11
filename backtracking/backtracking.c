#include <stdio.h>
#include <stdbool.h>
#include "backtrack.h"

bool finished = false;

void backtrack(int array[], int count, data input)
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
