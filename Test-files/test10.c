#include <stdio.h>

int main(void)
{
	int k, j;

	for (k = 0; k < 10; k++)
	{
		for (j = k + 1; j < 10; j++)
		{
			if (k != j)
			{
				putchar(k + '0');
				putchar(j + '0');
				if (k != 8 || j != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}