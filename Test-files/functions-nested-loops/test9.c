#include "test.h"

void times_table(void)
{
	int i, j, mult, u, d;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			mult = i * j;
			if (mult > 9)
			{
				u = mult % 10;
				d = (mult - u) / 10;

				_putchar(44);
				_putchar(32);
				_putchar(d + '0');
				_putchar(u + '0');
			}
			else
			{
				if (j != 0)
				{
					_putchar(44);
					_putchar(32);
					_putchar(32);
				}
				_putchar(mult + '0');
			}
		}
		_putchar('\n');
	}
}