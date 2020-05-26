#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

int main(void)
{
	int *input_data = (int[]){ 10, 4, 1, 2, 5, 3 };
	array numbers = { .size = 6, .data = input_data };
	merge_sort(&numbers);

	for (size_t i = 0; i < numbers.size; ++i) {
		printf(" %d", numbers.data[i]);
	}
	printf("\n");
	return EXIT_SUCCESS;
}
