#include "main.h"

/**
 * set_bit - sets the bit at the index
 * @n: the number to index
 * @index: the bit to set
 *
 * Return: 1 if successful, -1 on error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 64)
		return (-1);

	unsigned long int change = 1 << index;
	*n = *n | change;

	return (1);
}