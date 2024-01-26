#include "sort.h"

/**
 * bubble_sort - algorithm tha sort an array of
 * integers in ascending algorithm using Bubble sort
 * @array: Pointer to the array of integers to be sorted
 * @size: the size of the array of integers tobe sorted
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				print_array(array, size);
			}
		}
	}
}
