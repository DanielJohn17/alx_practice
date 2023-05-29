#include <stdio.h>

int main(void)
{
	char k = '0', n = 'a';

	while (k <= '9')
	{
		putchar(k);
		k++;
	}
	while (n <= 'f')
	{
		putchar(n);
		n++;
	}
	putchar('\n');
}