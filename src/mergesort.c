#include "mergesort.h"

void merge(array *first, array *second, int result[])
{
	size_t position_first = 0;
	size_t position_second = 0;
	size_t position = 0;

	while (position_first < first->size && position_second < second->size) {
		if (first->data[position_first] <
		    second->data[position_second]) {
			result[position] = first->data[position_first];
			position_first++;
		} else {
			result[position] = second->data[position_second];
			position_second++;
		}
		position++;
	}

	while (position_first < first->size) {
		result[position] = first->data[position_first];
		position_first++;
		position++;
	}
	while (position_second < second->size) {
		result[position] = second->data[position_second];
		position_second++;
		position++;
	}
}

void merge_sort(array *numbers)
{
	if (numbers->size == 1) {
		return;
	}

	if (numbers->size == 2) {
		if (numbers->data[0] > numbers->data[1]) {
			int tmp = numbers->data[0];
			numbers->data[0] = numbers->data[1];
			numbers->data[1] = tmp;
			return;
		}
	}

	size_t middle = numbers->size / 2;

	int *result = malloc(sizeof(int) * numbers->size);
	if (result == NULL) {
		abort();
	}

	array first = { .data = &numbers->data[0], .size = middle };
	merge_sort(&first);
	array second = { .data = &numbers->data[middle],
			 .size = numbers->size - middle };
	merge_sort(&second);
	merge(&first, &second, result);

	for (size_t i = 0; i < numbers->size; ++i) {
		numbers->data[i] = result[i];
	}

	if (result != NULL) {
		free(result);
	}
}
