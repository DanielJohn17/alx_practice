#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: number one.
 * @m: number two.
 *
 * Return: number of bits.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int xor = n ^ m;
	unsigned int count = 0;

	while (xor)
	{
		count = count + (xor&1);
		xor >>= 1;
	}
	return (count);
}