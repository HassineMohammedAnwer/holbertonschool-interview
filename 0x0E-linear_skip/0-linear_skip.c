#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * search_range - searches for a value in a range of nodes
 * @start: start node of the range
 * @stop: end node of the range
 * @value: value to search for
 * Return: a pointer to the node containing the value, or NULL if not found
 */
skiplist_t *search_range(skiplist_t *start, skiplist_t *stop, int value)
{
    skiplist_t *node = start;

    while (node && node != stop->next)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        if (node->n == value)
            return (node);
        node = node->next;
    }

    return (NULL);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the list
 * @value: value to search for
 * Return: a pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *node = list, *jump;

    if (!list)
        return (NULL);

    while (node->express)
    {
        jump = node->express;
        printf("Value checked at index [%lu] = [%d]\n", jump->index, jump->n);
        if (jump->n >= value)
        {
            printf("Value found between indexes [%lu] and [%lu]\n",
                    node->index, jump->index);
            return (search_range(node, jump, value));
        }
        node = jump;
    }

    while (node->next)
        node = node->next;

    printf("Value found between indexes [%lu] and [%lu]\n",
            node->index, node->index);
    return (search_range(node, node, value));
}
