#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using selection sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;

		/** Find the index of the minimum element in the unsorted part*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}

		temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;

		print_array(array, size);
	}
}
