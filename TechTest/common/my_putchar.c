#include <unistd.h>

/*
** my_putchar - Outputs a single character to standard output
** @c: character to print
**
** Uses write() system call for maximum compatibility and control
** write(1, &c, 1) outputs 1 byte to file descriptor 1 (stdout)
** Shared implementation used across all rush assignments
*/
void my_putchar(char c)
{
	write(1, &c, 1);
}
