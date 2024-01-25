#include <stdlib.h>

int _putchar(char c);

/**
 * decaleString - Decale a string to the left
 *
 * @s: The string
 *
 * Return: The string
 */

char *decaleString(char *s)
{
	char *t;

	t = s;

	while (*s != '0')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		*(s - 1) = *s;
		s++;
	}
	*s = '\0';
	*(s - 1) = '\0';
	s = t;

	return (t);
}

/**
 * addZero - Multiply a string by 10
 *
 * @s: The string
 * @i: Number of 0
 *
 * Return: The string
 */

char *addZero(char *s, int i)
{
	char *t;

	t = s;

	while (*s != '0')
		s++;
	for (; i > 0; i--)
	{
		while (*s)
		{
			*(s - 1) = *s;
			s++;
		}
		*(s - 1) = '0';
		s = t;
	}
	return (t);
}

/**
 * _strlen - Return the length of a string
 * @s: The string
 * Return: The length of s
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _puts - Print a string
 *
 * @str: the string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] == '0')
		i++;
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * resetTab - Put 0 on all case of a string
 * @tab: The string
 * @size: The size of the string
 */

void resetTab(char *tab, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		tab[i] = '0';
	}
}

/**
 * isDigit - Check if a string only contains number
 * @s: The string
 * Return: 1 for success, 0 if error
 */

int isDigit(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (1);
	}
	return (0);
}

/**
 * addNum - Add the 2 strings of int
 *
 *@c: First string
 *@n: Second string
 *
 * Return: The result of the addition
 */

char *addNum(char *c, char *n)
{
	int size = _strlen(c);
	int res, retenu = 0, i = size;
	char *r;

	r = malloc(size * sizeof(char));
	if (r == NULL)
		return (NULL);
	resetTab(r, size);

	while (*c != '\0')
		c++;
	while (*n != '\0')
		n++;
	c--;
	n--;

	for (; *c && *n; c--, n--, i--)
	{
		res = (*c - '0') + (*n - '0') + retenu;
		retenu = res / 10;
		r[i] = res % 10 + '0';
	}
	for (; *c; c--, i--)
	{
		res = *c - '0' + retenu;
		retenu = res / 10;
		r[i] = res % 10 + '0';
	}
	for (; *n; n--, i--)
	{
		res = *n - '0' + retenu;
		retenu = res / 10;
		r[i] = res % 10 + '0';
	}
	if (retenu > 0)
		r[i] = retenu + '0';
	decaleString(r);
	return (r);
}

/**
 * mulNum - Multiply the 2 strings of int
 *
 *@n1: First string
 *@n2: Second string
 *@r: The result of multiplication of one digit
 *@count: The result of addition of all the r
 *@size: The size of the string
 * Return: The result of the multiplication
 */

char *mulNum(char *n1, char *n2, char *r, char *count, int size)
{
	int i, j, res, retenu, temp = size, diz = 0;

	for (i = _strlen(n1) - 1; n1[i]; i--)
	{
		retenu = 0;
		size = temp;
		for (j = _strlen(n2) - 1; n2[j]; j--, size--)
		{
			res = (n1[i] - '0') * (n2[j] - '0') + retenu;
			retenu = res / 10;
			r[size] = res % 10 + '0';
		}
		if (retenu > 0)
		{
			r[size] = retenu + '0';
		}
		if (diz > 0)
			addZero(r, diz);
		decaleString(r);
		count = addNum(count, r);
		resetTab(r, temp);
		diz++;
	}

	return (count);
}

/**
 * main - Mulitplies two positive numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{
	int len1, len2, size;
	char *tabR, *tabC;
	char error[5] = "Error";

	if (argc != 3)
	{
		_puts(error);
		exit(98);
	}
	if (isDigit(argv[1]) || isDigit(argv[2]))
	{
		_puts(error);
		exit(98);
	}

	if (atoi(argv[1]) == 0 || atoi(argv[2]) == 0)
	{
		_putchar('0');
		_putchar('\n');
	}
	else
	{
		len1 = _strlen(argv[1]);
		len2 = _strlen(argv[2]);
		size = len1 + len2;
		tabR = malloc(size * sizeof(char));
		if (tabR == NULL)
			return (0);
		resetTab(tabR, size);
		tabC = malloc(size * sizeof(char));
		if (tabC == NULL)
			return (0);
		resetTab(tabC, size);
		tabC = mulNum(argv[1], argv[2], tabR, tabC, size);
		_puts(tabC);
	}
	return (0);
}
