#include <unistd.h>
#include "rush.h"

/*
** rush - Draws a rectangle with diagonal-mirror pattern
** @x: width (columns)
** @y: height (rows)
**
** Pattern: Diagonal symmetry - top corners (A, C), bottom corners (C, A)
** Creates X-axis mirror pattern around center
** Special case: Single row/column uses all 'B' characters
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
			/* Edge case: single row or column - all 'B' */
			if (x == 1 || y == 1)
				my_putchar('B');
			/* Top-left corner */
			else if (row == 0 && col == 0)
				my_putchar('A');
			/* Top-right corner */
			else if (row == 0 && col == x - 1)
				my_putchar('C');
			/* Bottom-left corner (mirrored: C) */
			else if (row == y - 1 && col == 0)
				my_putchar('C');
			/* Bottom-right corner (mirrored: A) */
			else if (row == y - 1 && col == x - 1)
				my_putchar('A');
			/* Top and bottom edges (excluding corners) */
			else if (row == 0 || row == y - 1)
				my_putchar('B');
			/* Left and right edges (excluding corners) */
			else if (col == 0 || col == x - 1)
				my_putchar('B');
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
