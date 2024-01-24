#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @size: Size of the array
 *
 * Return: Nothing(void)
 */
size_t lomuto_partition(int *array, size_t size)
{
	int temp;
	size_t j;
	int pivot = array[size - 1];
	int i = 0;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			/* Swap array[i] and array[j]*/
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;

			print_array(array, size);
		}
	}
	/* Swap array[i + 1] and array[high] to place pivot in the correct position*/
	temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;
	print_array(array, size);

	return (i);
}

/**
 * quick_sort- Sorts an array in ascending order using Quick
 *             sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	size_t pivot_index;

	if (size <= 1)
		return;

	pivot_index = lomuto_partition(array, size);

	quick_sort(array, pivot_index);
	quick_sort(array + pivot_index +  1, size - pivot_index - 1);
}
