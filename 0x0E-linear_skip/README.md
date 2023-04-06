# Description
This project is about implementing a linear search algorithm in a Skip List data structure. A Skip List is a linked list with an "express lane" that enables faster searching by skipping over elements that are less likely to contain the searched value.

## Files
search.h: Header file containing the definition of the skiplist_t data structure and the prototype of the linear_skip function.
0-linear_skip.c: Source code file that implements the linear_skip function.
## Function Prototype
skiplist_t *linear_skip(skiplist_t *list, int value);
## New Data Structures
We have defined a new data structure called skiplist_t in the search.h header file. The structure is a singly linked list that has an "express lane" to make searches faster. Each node contains an integer value n, an index index, a pointer to the next node next, and a pointer to the next node in the express lane express. The skiplist_t structure is used in the implementation of the linear_skip function.

## Function Implementation
The linear_skip function takes a pointer to the head of a skip list list and an integer value value to search for in the list. It returns a pointer to the first node where value is located or NULL if value is not present in the list or if the list is NULL. The function uses the "express lane" to perform a search, which is faster than searching the entire list. The "express lane" is a linked list that skips over nodes in the list by a certain interval to make the search faster.

## Function Description
The linear_skip function starts by checking if list is NULL or if value is less than the first node's value in the list. If either of these conditions is true, the function returns NULL because the value cannot be found in the list.

The function then uses the "express lane" to skip over nodes in the list until it finds a node whose n value is greater than or equal to value or the end of the list. When the function finds this node, it performs a linear search on the nodes between the current node and the previous node in the "express lane" to find the value. If the value is found, the function returns a pointer to the node containing the value. Otherwise, the function returns NULL.

## Example Usage
The linear_skip function can be used to search for a value in a skip list. To use the function, you first need to create a skip list using the create_skiplist function. The create_skiplist function takes an array of integers and the size of the array as arguments and returns a pointer to the head of the skip list.
You can then use the linear_skip function to search for a value in the skip list. The function takes a pointer to the head of the skip list and the value to search for as arguments and returns a pointer to the node containing the value or NULL if the value is not present in the skip list.

## Conclusion
The linear_skip function is a faster way to search for a value in a skip list than searching the entire list. It uses an "express lane" to skip over nodes in the list and performs a linear search on a smaller subset of the list to find the value. The function is useful when searching large lists or when searching for values that are unlikely to be in the list.01~
