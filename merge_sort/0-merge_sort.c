#include "sort.h"

/**
 * merge - merge two sorted sub-arrays into single sorted sub-array
 * @array: original array
 * @tmp: Tmp array for merging
 * @l: starting index of left sub-array
 * @m: Ending index of left sub-array
 * @r: Ending index of right sub-array
 */
void merge(int *array, int *tmp, size_t l, size_t m, size_t r)
{
    size_t a = l;
    size_t b = m + 1;
    size_t c = l;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array + l, m - l + 1);
    printf("[right]: ");
    print_array(array + m + 1, r - m);

    while (a <= m && b <= r)
    {
        if (array[a] <= array[b])
            tmp[c++] = array[a++];
        else
            tmp[c++] = array[b++];
    }

    while (a <= m)
        tmp[c++] = array[a++];
    while (b <= r)
        tmp[c++] = array[b++];
    for (c = l; c <= r; c++)
        array[c] = tmp[c];
    printf("[Done]: ");
    print_array(array + l, r - l + 1);
}

/**
 * merge_sort_r - sorts an array using Merge Sort ecursively
 * @array: array to sort
 * @tmp: tmp array for merging
 * @l: starting index
 * @r: ending index
 */
void merge_sort_r(int *array, int *tmp, size_t l, size_t r)
{
    if (l >= r)
        return;

    size_t n = r - l + 1;
    size_t l_size = n / 2;
    size_t m = l + l_size - 1;

    merge_sort_r(array, tmp, l, m);
    merge_sort_r(array, tmp, m + 1, r);
    merge(array, tmp, l, m, r);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: array to sort
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    int *tmp;

    if (size < 2 || array == NULL)
        return;
    tmp = malloc(sizeof(int) * size);
    if (tmp == NULL)
        return;
    merge_sort_r(array, tmp, 0, size - 1);
    free(tmp);
}