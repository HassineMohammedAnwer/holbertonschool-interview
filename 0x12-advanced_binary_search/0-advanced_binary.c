#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - search for value.
 * @array: Pointer to the first element of a sorted array.
 * @size: of array.
 * @value: Value to search for.
 *
 * Return: the index of the first value in the array.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t index, mid;
	int result;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (index = 0; index < size; index++)
		//prints each element of the array followed by a comma and a space
		//except for the last element which is followed by a newline
		printf(index == size - 1 ? "%d\n" : "%d, ", array[index]);

	if (size == 1 && array[0] != value)
		return (-1);

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] < value)
			return (mid);
		return (advanced_binary(array, mid + 1, value));
	}

	else if (array[mid] > value)
		return (advanced_binary(array, mid + 1, value));
	result = advanced_binary(array + mid + 1, size - mid - 1, value);

	if (result == -1)
		return (-1);

	return (mid + 1 + result);
}

