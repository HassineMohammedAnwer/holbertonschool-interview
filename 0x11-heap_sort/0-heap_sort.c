#include "sort.h"

/**
 * swap - swap the position of two elements
 *
 * @x: 1st num
 * @y: 2nd num
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * heapify - ensures that the subtree with root at index i
 *           (represented as an array) satisfies the heap property
 * @arr: The array to convert
 * @size: The size of the array
 * @i: The root index of the heap
 * @total_size: The total size of the heap
 */
void heapify(int *arr, size_t size, int i, size_t total_size)
{
	int max = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int s = (int)size;

	if (arr[l] > arr[max] && l < s)
		max = l;

	if (arr[r] > arr[max] && r < s)
		max = r;
	/*If , it swaps the element at i with its largest child*/
	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		print_array(arr, total_size);
		heapify(arr, size, max, total_size);
	}
}

/**
 * heap_sort - sorts in ascending order using the Heap sort
 *
 * @array: array to be sorted
 * @size: num of elements of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
		{
			print_array(array, size);
			heapify(array, i, 0, size);
		}
	}
}
