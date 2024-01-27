#include "sort.h"

/**
 * swap - swaps the elements of array
 * @xp: index at element to be swapped
 * @yp: index at element to be swapped
 * Return: Nothing
 */

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - sorts array in ascending order in Selection Sort
 * @array: pointer to an array
 * @size: the length of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_idx] > array[j])
			{
				min_idx = j;
			}
		}
		swap(&array[i], &array[min_idx]);
		print_array(array, size);
	}
}
