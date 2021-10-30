#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_num;
	int cont, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_num = i;
		cont = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_num] > array[j])
			{
				min_num = j;
				cont++;
			}
		}
		tmp = array[i];
		array[i] = array[min_num];
		array[min_num] = tmp;
		if (cont > 0)
			print_array(array, size);
	}
}
