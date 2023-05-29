#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* betty style doc for function main goes there */
int main(void)
{
	int n;
	char last[] = "Last digit of";

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n % 10 > 5)
	{
		printf("%s %d is %d and is greater than 5 and not 0\n", last, n, n % 10);
	}
	else if (n % 10 < 6)
	{
		printf("%s %d is %d and is less than 6 and not 0\n", last, n, n % 10);
	}
	else
	{
		printf("%s %d is %d and is 0\n", last, n, n % 10);
	}
	return (0);
}
