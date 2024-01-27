#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using Shell sort Algorithm
 * @array: pointer to the array of integers
 * @size: size of the array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;
	
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1);
	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
