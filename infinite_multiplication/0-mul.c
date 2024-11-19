#include <stdio.h>
#include <stdlib.h>

/**
 * _isdigit - Check if a char is digit
 * @c: char
 * Return: 1 if c is digit, 0 otherwise
 */
int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * mul - Multiply two positive numbers represented as strings
 * @num1: num1 will be passed in base 10
 * @num2: num2 will be passed in base 10
 */
void mul(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, carry = 0, sum;
	int *result;

	while (num1[len1])
	{
		if (!_isdigit(num1[len1]))
		{
			printf("Error\n");
			exit(98);
		}
		len1++;
	}

	while (num2[len2])
	{
		if (!_isdigit(num2[len2]))
		{
			printf("Error\n");
			exit(98);
		}
		len2++;
	}
	result = calloc(len1 + len2, sizeof(int));
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i] += carry;
	}

	i = 0;
	while (i < len1 + len2 - 1 && result[i] == 0)
		i++;
	while (i < len1 + len2)
		printf("%d", result[i++]);
	printf("\n");
	free(result);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3) 
	{
		printf("Error\n");
		exit(98);
	}
	mul(argv[1], argv[2]);
	return (0);
}
