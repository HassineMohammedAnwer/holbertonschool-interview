#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - checks if a linked list contains a cycle
 *
 * @list: a pointer to the head of the linked list
 *
 * Return: 1 if the linked list contains a cycle, otherwise 0
 */
int check_cycle(listint_t *list)
{
	listint_t *turtle, *hare;	/* pointers to nodes in the linked list */

	if (list == NULL || list->next == NULL)	/* check for empty list
						or single node list */
		return (0);

	turtle = list;	/* initialize turtle pointer
			to the head of the list */
	hare = list->next;	/* initialize hare pointer
				to the second node in the list */

	while (hare != NULL && hare->next != NULL)	/* loop while
							hare pointer is not
							at the end of the list */
	{
		if (turtle == hare)	/* check if turtle
					and hare pointers
					point to the same node */
			return (1);

		turtle = turtle->next;	/* move turtle
					pointer one node forward */
		hare = hare->next->next;	/* move hare pointer
						two nodes forward */
	}

	return (0);	/* if hare pointer reaches
			end of list, there is no cycle */
}
