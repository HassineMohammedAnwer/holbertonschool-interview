#include "lists.h"

/**
 * reverse_list - reverse a linked list
 * @head: double pointer to head of list
 *
 * Return: reversed linked list
 */
listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL, *next = NULL;
	listint_t *curr = *head;

	while (curr)
	{
		next = curr->next;
		 curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head = prev;

	return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 *
 * Return: 1 if it is a palindrome, 0 if it is not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	listint_t *prev_of_slow = *head, *second_half = NULL;
	int result = 1;

	if (!(*head) || !(*head)->next)
		return (1);

	while (fast && fast->next)
	{
		fast = fast->next->next;
		prev_of_slow = slow;
		slow = slow->next;
	}

	/* if odd number of nodes, skip the middle node */
	if (fast)
		slow = slow->next;

	/* reverse the second half of the linked list */
	second_half = reverse_list(&slow);
	*head = *head;

	/* compare first and second halves */
	while (second_half)
	{
		if ((*head)->n != second_half->n)
		{
			result = 0;
			break;
		}
		(*head) = (*head)->next;
		second_half = second_half->next;
	}

	/* reverse the second half again to restore the original linked list */
	reverse_list(&slow);

	/* adjust the head to the original first node */
	*head = prev_of_slow;

	return (result);
}
