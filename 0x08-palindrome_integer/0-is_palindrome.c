#include "palindrome.h"

/**
 * is_palindrome - checks whether a given unsigned integer is a palindrome
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, temp = n;

	while (temp != 0)
	{
		rev = rev * 10 + (temp % 10);
		temp = temp / 10;
	}

	return (n == rev);
}
