#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * insert_node: inserts a number to add
 * @head: pointer of the list
 * @number: declaration
 * Return: code
 */
listint_t *insert_node(listint_t **head, int number){

	/* pointers for listint */
	listint_t *current, *prev;
	current = prev = *head;

	/* Allocate memory */
	listint_t *new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->n = number;

	/*  make the new node the head if the linkedlist not empty */
	if (!(*head)) {
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}

	/* make it the new head if the condistion is right */
	if ((*head)->n >= new_node->n) {
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the linked list */
	while (current && current->n < number) {
		prev = current;
		current = current->next;
	}

	/* new node */
	new_node->next = current;
	prev->next = new_node;

	return (new_node);
}
