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
 * lomuto_partition - partitions an array of integers using
 * the Lomuto partition scheme
 * @array: array to partition
 * @lo: lower index of the partition to sort
 * @hi: higher index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * using quick sort algorithm
 * @array: the array to sort
 * @lo: lower index of the partion sort
 * @hi: higest index of the partion sort
 * @size: the size of the array
 * Return: Nothing
 */

void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending
 * order using the quick sort algoritm
 * @array: pointer to the array of integers to be sorted
 * @size: the length of the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
