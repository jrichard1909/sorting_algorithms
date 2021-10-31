#include "sort.h"

/**
 * quick_sort2 - sorts an array of integers in ascending order
 * @array: array
 * @first: first idx
 * @last: last index
 * @size: size
 */

void quick_sort2(int *array, size_t first, size_t last, size_t size)
{
	size_t first_idx = first, last_idx = last, pivot = last, i = first;
	int first_num = array[first], tmp;

	for (; i < last_idx; i++)
	{
		if (first_num > array[pivot])
		{
			tmp = array[first];
			array[first] = array[pivot];
			array[pivot] = tmp;
			first++;
			pivot = first;
			print_array(array, size);
		}
		else if (first_num != array[pivot])
		{
			tmp = array[last];
			array[last] = array[pivot];
			array[pivot] = tmp;
			last--;
			pivot = last;
		}
	}

	if (pivot != 0)
		quick_sort2(array, first_idx, pivot - 1, size);
	if (pivot != last_idx)
		quick_sort2(array, pivot + 1, last_idx, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	quick_sort2(array, 0, size - 1, size);
}
