#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int temp;
	int j;
	int pivot = array[high];
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			/* Swap array[i] and array[j]*/
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}
	/* Swap array[i + 1] and array[high] to place pivot in the correct position*/
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to implement Quick sort
 * @array: Array to be sorted
 * @low: Low index of the partition
 * @high: High index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivotIndex;

	if (low < high)
	{
		pivotIndex = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivotIndex - 1, size);
		quick_sort_recursive(array, pivotIndex + 1, high, size);
	}
}

/**
 * quick_sort- Sorts an array in ascending order using Quick
 *             sort algorithm.
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
