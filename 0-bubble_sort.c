#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble sort algorithm.
 * @array : Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 * Return : Returns nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;
	int temp;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;

				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
