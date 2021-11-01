#include "sort.h"

/**
 * quick_sort2 - sorts an array of integers in ascending order
 * @array: array
 * @first: first idx
 * @last: last index
 * @size: size
 */

void quick_sort2(int *array, int first, int last, size_t size)
{
	int pivot_idx = last, i, j = first;
	int pivot_num = array[last], tmp;

	if (first >= last)
		return;

	for (i = first; i < last; i++)
	{
		if (pivot_num >= array[i])
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			j++;
		}
	}

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}

	pivot_idx = j;

	quick_sort2(array, first, pivot_idx - 1, size);
	quick_sort2(array, pivot_idx + 1, last, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort2(array, 0, size - 1, size);
}
