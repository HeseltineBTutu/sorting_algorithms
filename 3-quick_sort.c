#include "sort.h"

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: Array of integers.
 * @size: Size of the array
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index
 */
size_t lomuto_partition(int *array, size_t size, int left, int right)
{
	int temp;
	int j;
	int pivot = array[right];
	int i = left;

	for (j = left; j < right; j++)
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
	array[i] = array[right];
	array[right] = temp;
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

	if (array == NULL || size < 2)
		return;

	pivot_index = lomuto_partition(array, size, 0, size - 1);

	if (pivot_index > 0)
		quick_sort(array, pivot_index);
	quick_sort(array + pivot_index +  1, size - (pivot_index + 1));
}
