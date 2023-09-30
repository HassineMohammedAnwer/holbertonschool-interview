#include <stdio.h>
#include <math.h>


void chr_draw(int c, int r, char chr, int level);

/**
 * menger - a 2D version of the Menger sponge
 *
 * @level : size of cube
 */
void menger(int level)
{
	int size = (int) pow(3, level);

	if (level < 0)
		return;

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			chr_draw(col, row, '#', level);
		}
		putchar('\n');
	}
}

/**
 * chr_draw - Draws
 * @c: column
 * @r: row
 * @chr: # or space
 * @level: of the Menger Sponge
 */
void chr_draw(int c, int r, char chr, int level)
{
	while (level > 0)
	{
		if (c % 3 == 1 && r % 3 == 1)
		{
			chr = ' ';
		}
		c /= 3;
		r /= 3;
		level = level - 1;
	}
	putchar(chr);
}
