#include <stddef.h>
#include <stdlib.h>

typedef struct array array;
struct array {
	size_t size;
	int *data;
};

void merge(array *first, array *second, int result[]);
void merge_sort(array *numbers);
