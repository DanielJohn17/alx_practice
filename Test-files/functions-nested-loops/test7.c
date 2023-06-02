#include "test.h"

int print_last_digit(int num)
{
	int last;

	last = num % 10;
	if (last < 0)
	{
		last *= -1;
	}
	_putchar(last + '0');
	return (last);
}