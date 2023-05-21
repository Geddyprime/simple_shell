#include "shell.h"

/**
 * _strcpy - ~This copies a str&&
 * @dest: ~destination&&
 * @src: ~source&&
 *
 * Return: ~pointer to destination...
 */
char *_strcpy(char *dest, char *src)
{
	int k = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return (dest);
}

/**
 * _strdup - ~This duplicates a str&&
 * @str: ~string to duplicate&&
 *
 * Return: ~pointer to the duplicated str&&
 */
char *_strdup(const char *str)
{
	int l = 0;/* Where l == length*/
	char *rt;

	if (str == NULL)
		return (NULL);
	while (*str++)
		l++;
	rt = malloc(sizeof(char) * (l + 1));
	if (!rt)
		return (NULL);
	for (l++; l--;)
		rt[l] = *--str;
	return (rt);
}

/**
 * _puts - ~This prints an inputed str&&
 * @str: ~string to be printed&&
 *
 * Return: ~Zero...
 */
void _puts(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
}

/**
 * _putchar - ~This writes char c to stdout&&
 * @c: ~character to print&&
 *
 * Return: On success 1...
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
