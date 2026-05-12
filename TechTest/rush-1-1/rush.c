#include <unistd.h>
#include "rush.h"

/*
** rush - Draws a rectangle with specified dimensions
** @x: width (columns)
** @y: height (rows)
**
** Pattern: Classic rectangle with corners 'o', edges '-' and '|', interior ' '
** Validates input and outputs error message to stderr if invalid
*/
void rush(int x, int y)
{
	int row;
	int col;

	/* Validate dimensions - reject zero or negative values */
	if (x <= 0 || y <= 0)
	{
		write(2, "Invalid size\n", 13);
		return ;
	}

	/* Outer loop: iterate through each row */
	row = 0;
	while (row < y)
	{
		/* Inner loop: iterate through each column */
		col = 0;
		while (col < x)
		{
			/* Corner positions: top-left, top-right, bottom-left, bottom-right */
			if ((row == 0 || row == y - 1) && (col == 0 || col == x - 1))
				my_putchar('o');
			/* Top and bottom edges (excluding corners) */
			else if (row == 0 || row == y - 1)
				my_putchar('-');
			/* Left and right edges (excluding corners) */
			else if (col == 0 || col == x - 1)
				my_putchar('|');
			/* Interior spaces */
			else
				my_putchar(' ');
			col++;
		}
		/* End of line: print newline after each row */
		my_putchar('\n');
		row++;
	}
}
