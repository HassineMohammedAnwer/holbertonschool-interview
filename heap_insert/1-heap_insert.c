#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * tree_size - function to calculate the size of a binary tree
 * @node: pointer to the root node of the tree
 * Return: size of the tree, or 0 if node is NULL
 */
size_t tree_size(const binary_tree_t *node)
{
	size_t size = 1;

	if (!node)
		return (0);
	if (node->left != NULL)
		size = size + tree_size(node->left);
	if (node->right != NULL)
		size = size + tree_size(node->right);
	return (size);
}

/**
 * is_perfect_tree - function to check if a binary tree is perfect
 * @node: pointer to the root node of the tree
 * Return: 1 if the tree is perfect, 0 otherwise or if node is NULL
 */
int is_perfect_tree(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (tree_size(node->left) == tree_size(node->right))
		return (1);
	return (0);
}


/**
 * swap_nodes - function to swap two nodes in a binary tree
 * @child: pointer to the child node
 * @parent: pointer to the parent node
 * Return: None
 */
void swap_nodes(binary_tree_t **child, binary_tree_t **parent)
{
	binary_tree_t *left_side, *right_side, *son = *child, *father = *parent;

	right_side = (*child)->right, left_side = (*child)->left;

	if (son->n > father->n)
	{
		if (son->left)
			son->left->parent = father;
		if (son->right)
			son->right->parent = father;
		if (father->left == son)
		{
			if (father->right)
				father->right->parent = son;
			son->right = father->right;
			son->left = father;
		}
		else
		{
			father->left->parent = son;
			son->left = father->left;
			son->right = father;
		}
		if (father->parent)
		{
			if (father->parent->left == father)
				father->parent->left = son;
			else
				father->parent->right = son;
		}
		else
		{
			*parent = son;
		}
		son->parent = father->parent;
		father->parent = son;
		father->left = left_side;
		father->right = right_side;
	}
}


/**
 * *heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 * Return:  a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_tree;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (is_perfect_tree(*root) || (!is_perfect_tree((*root)->left)))
	{
		if ((*root)->left != NULL)
		{
			new_tree = heap_insert(&((*root))->left, value);
			swap_nodes(&((*root)->left), root);
			return (new_tree);
		}
		else
		{
			new_tree = binary_tree_node(*root, value);
			(*root)->left = new_tree;
			swap_nodes(&((*root)->left), root);
			return (new_tree);
		}
	}
	else
	{
		if ((*root)->right != NULL)
		{
			new_tree = heap_insert(&((*root)->right), value);
			swap_nodes(&((*root)->right), root);
			return (new_tree);
		}
		else
		{
			new_tree = binary_tree_node(*root, value);
			(*root)->right = new_tree;
			swap_nodes(&((*root)->right), root);
			return (new_tree);
		}
	}
	return (NULL);
}
