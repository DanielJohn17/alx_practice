#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0.
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 0 if it worked, -1 if it didn't.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int change;

	if (index >= 64)
		return (-1);

	change = ~(1 << index);
	*n = *n & change;

	return (1);
}