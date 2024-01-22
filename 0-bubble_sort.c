#include "sort.h"
/**
 * bubble_sort - a function that sorts an array of integers in
 *               ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * size: size of the array
 *
 * Return: Returns nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	bool swapped;
	int temp;

	if (size < 2)
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

				for (k = 0; k < size; k++)
				{
					print_array(array, size);
				}
				printf("\n");
			}
		}
		if (!swapped)
			break;
	}
}
