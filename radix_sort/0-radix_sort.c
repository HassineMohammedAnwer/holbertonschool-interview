#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - find max value in array
 *
 * @array: The array to find the maximum value in
 * @size: Number of elements in @array
 * Return: max value in array
 */
int get_max(int *array, size_t size)
{
    int res = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > res)
            res = array[i];
    }
    return res;
}

/**
 * counting_sort - Perform counting sort on the array based on the digit
 * represented by exp (10^i where i is the current digit place)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * @exp: The current digit place (1, 10, 100, ...)
 */
void counting_sort(int *array, size_t size, int exp)
{
    int *output = malloc(size * sizeof(int));
    int count[10] = {0};
    size_t i;

    if (!output)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < size; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);

    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm (LSD approach)
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
    int max = get_max(array, size);
    int exp;

    if (array == NULL || size < 2)
        return;
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
    }
}
