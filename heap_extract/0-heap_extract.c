#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * get_last_node - finds last node in the heap.
 * @root: pointer to root node of heap.
 * Return: pointer to last node, NULL if empty.
 */
 static heap_t *get_last_node(heap_t *root)
 {
	 heap_t *queue[1024];
	 int f = 0, l = 0;
	 heap_t *last = NULL;
 
	 if (!root)
		 return (NULL);
 
	 queue[l++] = root;
	 while (f < l)
	 {
		 last = queue[f++];
		 if (last->left)
			 queue[l++] = last->left;
		 if (last->right)
			 queue[l++] = last->right;
	 }
	 return (last);
 }
 
 /**
  * heapify_down - rebuilds the Max Heap by moving a node down to its correct position.
  * @root: pointer to root node of the heap.
  */
 static void heapify_down(heap_t *root)
 {
	 heap_t *largest, *tmp;
 
	 while (root)
	 {
		 largest = root;

		 if (root->left && root->left->n > largest->n)
			 largest = root->left;
		 if (root->right && root->right->n > largest->n)
			 largest = root->right;
		 if (largest != root)
		 {
			 tmp = root->n;
			 root->n = largest->n;
			 largest->n = tmp;
			 root = largest;
		 }
		 else
			 break;
	 }
 }
 
 /**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root of the heap
 * Return: the value stored in the root node, or 0.
 */
 int heap_extract(heap_t **root)
 {
	 int value;
	 heap_t *last_node, *parent;

	 if (!root || !*root)
		 return (0);
	 value = (*root)->n;
	 if (!(*root)->left && !(*root)->right)
	 {
		 free(*root);
		 *root = NULL;
		 return (value);
	 }
	 last_node = get_last_node(*root);
	 if (!last_node)
		 return (0);
	 (*root)->n = last_node->n;
	 parent = last_node->parent;
	 if (parent)
	 {
		 if (parent->left == last_node)
			 parent->left = NULL;
		 else
			 parent->right = NULL;
	 }
	 free(last_node);
	 heapify_down(*root);
 
	 return (value);
 }
