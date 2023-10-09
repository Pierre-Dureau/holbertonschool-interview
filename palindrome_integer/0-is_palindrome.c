#include "palindrome.h"

/**
 * inverse_int - Inverse an int
 *
 * @n: unsigned long int
 * Return: The int inversed
 */

unsigned long int inverse_int(unsigned long n)
{
	int temp = 0;

	while (n > 0)
	{
		temp = (temp * 10) + (n % 10);
		n /= 10;
	}

	return (temp);
}

/**
 * is_palindrome - Check if an int is a palindrome
 *
 * @n: unsigned long int
 * Return: 1 if yes, 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	return (n == inverse_int(n));
}
