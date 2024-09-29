#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - a 2D version of the Menger sponge
 *
 * @level: size of cube
 */
void menger(int level)
{
	int size = (int)pow(3, level);

	if (level < 0)
		return;

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			char chr = '#';
			int c = col, r = row;
			int l = level;

			while (l > 0)
			{
				if (c % 3 == 1 && r % 3 == 1)
				{
					chr = ' ';
				}
				c /= 3;
				r /= 3;
				l = l - 1;
			}

			putchar(chr);
		}
		putchar('\n');
	}
}
