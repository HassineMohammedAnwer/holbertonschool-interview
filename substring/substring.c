#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "substring.h"

/**
 * find_substring - finds all the possible substrings
 * containing a list of words, within a given string.
 * @s: pointer to the string to scan.
 * @words: pointer to the The array of words to match.
 * @nb_words: The number of words in `words`.
 * @n: pointer to store the number of indices found.
 * Return: An allocated array of indices, or NULL if no indices are found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
    int s_len = strlen(s);
    int word_len = strlen(words[0]);
    int *result = malloc(s_len * sizeof(*result));
    int *word_count = calloc(nb_words, sizeof(int));
    int i, j, k, r;

    if (!s || !words || !*words || !n || nb_words < 1)
		return (NULL);
    for (i = 0, *n = 0; i <= s_len - nb_words * word_len; i++)
	{
		r = nb_words;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (word_count[k] == 0 && strncmp(s + i + j * word_len, words[k], word_len) == 0)
				{
					word_count[k] = 1;
					r--;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (r == 0)
			result[(*n)++] = i;
		memset(word_count, 0, nb_words * sizeof(*word_count));
	}

	free(word_count);

	return ((*n) > 0 ? result : NULL);
}