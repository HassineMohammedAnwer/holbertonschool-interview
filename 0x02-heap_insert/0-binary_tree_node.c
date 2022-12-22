#include "binary_trees.h"
/**
 * binary_tree_node - creates binary tree
 * @parent: parent to the pointer node
 * @value: the value to put a new node
 * Return: NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *bt_new_node;
	bt_new_node = malloc(sizeof(binary_tree_t));
	if (!bt_new_node)
		return (NULL);
	bt_new_node->parent = parent;
	bt_new_node->n = value;
	bt_new_node->left = NULL;
	bt_new_node->right = NULL;
	return (bt_new_node);
}
