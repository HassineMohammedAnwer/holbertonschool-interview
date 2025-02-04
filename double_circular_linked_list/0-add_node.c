#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a doubly circular linked list.
 * @list: Pointer to the pointer of the list.
 * @str: The string to be added to the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
    List *new_node = malloc(sizeof(List));
    if (!new_node)
        return NULL;

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return NULL;
    }

    if (*list == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
        *list = new_node;
    }
    else
    {
        List *last = (*list)->prev;
        new_node->next = *list;
        new_node->prev = last;
        last->next = new_node;
        (*list)->prev = new_node;
    }

    return new_node;
}

/**
 * add_node_begin - Adds a new node to the beginning of a doubly circular linked list.
 * @list: Pointer to the pointer of the list.
 * @str: The string to be added to the new node.
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node = malloc(sizeof(List));
    if (!new_node)
        return NULL;

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return NULL;
    }

    if (*list == NULL)
    {
        new_node->prev = new_node;
        new_node->next = new_node;
    }
    else
    {
        List *last = (*list)->prev;
        new_node->next = *list;
        new_node->prev = last;
        last->next = new_node;
        (*list)->prev = new_node;
    }

    *list = new_node;
    return new_node;
}