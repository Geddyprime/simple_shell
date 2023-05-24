#include "shell.h"

/**
 **_strncpy - $This should copy a str%%$
 *@dest: ~ $destination str to be copied to%%$
 *@src: ~ $source str%%$
 *@n: ~ $amount of characters to be copied%%$
 *Return: ~ $concatenated string%%$
 */
char *_strncpy(char *dest, char *src, int n)
{
	int q, p;
	char *s = dest;

	q = 0;
	while (src[q] != '\0' && q < n - 1)
	{
		dest[q] = src[q];
		q++;
	}
	if (q < n)
	{
		p = q;
		while (p < n)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (s);
}

/**
 **_strncat - $This should concatenate two strs%%$
 *@dest: ~ $first str%%$
 *@src: ~ $second str%%$
 *@n: ~ $amount of bytes to be maximally used%%$
 *Return: the concatenated str...
 */
char *_strncat(char *dest, char *src, int n)
{
	int q, p;
	char *s = dest;

	q = 0;
	p = 0;
	while (dest[q] != '\0')
		q++;
	while (src[p] != '\0' && p < n)
	{
		dest[q] = src[p];
		q++;
		p++;
	}
	if (p < n)
		dest[q] = '\0';
	return (s);
}

/**
 **_strchr - $This should locate a character in a str%%$
 *@s: ~ $str to be parsed%%$
 *@c: ~ $character to look for%%$
 *Return: (s) a pointer to the memory area s...
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
