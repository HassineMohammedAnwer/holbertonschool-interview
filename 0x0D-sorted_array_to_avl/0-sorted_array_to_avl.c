#include "binary_trees.h"

/**
 * recursive_build_avl_tree - Recursively builds an AVL tree from a sorted arr
 *
 * @array: Pointer to the first element of the array to be converted
 * @start: Index of the first element of the current array
 * @end: Index of the last element of the current array
 * @parent: Pointer to the parent node of the current node being created
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *recursive_build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	int middle;
	avl_t *new_node;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = array[middle];
	new_node->parent = parent;
	new_node->left = recursive_build_avl_tree(array, start, middle - 1, new_node);
	new_node->right = recursive_build_avl_tree(array, middle + 1, end, new_node);

	return (new_node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: The sorted array
 * @size: The size of the array
 *
 * Return: The root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (recursive_build_avl_tree(array, 0, size - 1, NULL));
}

