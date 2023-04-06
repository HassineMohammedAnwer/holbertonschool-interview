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
skiplist_t *search_range(skiplist_t *p, skiplist_t *current, int n)
{
	for (; p != current->next; p = p->next)
	{
		if (p->n == n)
			return (p);
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
	skiplist_t *current = list, *p = list;

	while (current)
	{
		if ((current->n < value || ((current->n == value) &&
			!(search_range(p, current, value)))) && current->next)
		{
			if (current->index)
				printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);
			p = current;
			if (!current->express)
			{
				while (current->next)
					current = current->next;
			}
			else
				current = current->express;
		}
		else
		{
			if (p->n > value)
				return (NULL);
			if (current->n >= value)
				printf("Value checked at index [%lu] = [%d]\n",
					current->index, current->n);
			printf("Value found between indexes [%lu] and [%lu]\n",
				p->index, current->index);
			for (; p && p != current->next; p = p->next)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					p->index, p->n);
				if (p->n == value)
					return (p);
			}
			return (NULL);
		}
	}
	return (NULL);
}
