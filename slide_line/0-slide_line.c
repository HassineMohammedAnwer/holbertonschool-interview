#include "slide_line.h"

/**
 * slide_line - slide & merge it to the left or to the right.
 * @line: array of integers containing size elements,
 * @size: size of array
 * @direction: direction left or right
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, p = 0;
    int prev = 0;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);
    if (size == 0)
        return (1);

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (prev == 0)
                    prev = line[i];
                else if (prev == line[i])
                {
                    line[p++] = prev * 2;
                    prev = 0;
                }
                else
                {
                    line[p++] = prev;
                    prev = line[i];
                }
            }
        }
        if (prev != 0)
            line[p++] = prev;
    }
    else
    {
        p = size;
        for (i = size; i > 0; i--)
        {
            if (line[i - 1] != 0)
            {
                if (prev == 0)
                    prev = line[i - 1];
                else if (prev == line[i - 1])
                {
                    line[--p] = prev * 2;
                    prev = 0;
                }
                else
                {
                    line[--p] = prev;
                    prev = line[i - 1];
                }
            }
        }
        if (prev != 0)
            line[--p] = prev;
    }

    if (direction == SLIDE_LEFT)
        while (p < size)
            line[p++] = 0;
    else
        while (p > 0)
            line[--p] = 0;

    return (1);
}