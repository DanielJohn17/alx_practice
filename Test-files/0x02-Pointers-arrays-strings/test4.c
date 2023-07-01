#include "test.h"

void reverse_array(int *a, int n)
{
	int i, j, temp;

	for (i = 0; i < n - i; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];

		a[n - i - 1] = temp;
	}
}