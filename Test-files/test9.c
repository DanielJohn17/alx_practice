#include <stdio.h>

int main(void)
{
	char k = '0';

	while (k <= '9')
	{
		putchar(k);
		if (k != '9')
		{
			putchar(',');
			putchar(' ');
		}
		k++;
	}
	putchar('\n');

	return (0);
}