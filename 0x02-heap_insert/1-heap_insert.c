#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function to check if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (!node)
        return (0);

    if (!node->left && !node->right)
        return (1);

    return (0);
}

/**
 * heap_insert - insert a new node into a binary max heap
 * @root: a pointer to the root node of the heap
 * @value: the value of the new node
 * Return: a pointer to the newly inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *current;

    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    current = *root;
    while (current)
    {
        if (!current->left)
        {
            new_node = binary_tree_node(current, value);
            current->left = new_node;
            break;
        }
        else if (!current->right)
        {
            new_node = binary_tree_node(current, value);
            current->right = new_node;
            break;
        }
        else if (binary_tree_is_leaf(current->left))
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    while (new_node->parent && new_node->n > new_node->parent->n)
    {
        int temp = new_node->n;
        new_node->n = new_node->parent->n;
        new_node->parent->n = temp;
        new_node = new_node->parent;
    }

    return (new_node);
}
