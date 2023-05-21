#include "shell.h"

/**
 * _strlen - ~Should return the length of a str&&
 * @s: ~str whose length to check&&
 *
 * Return: ~integer length of str&&
 */
int _strlen(char *s)
{
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;
	return (k);
}

/**
 * _strcmp - ~This performs lexicogarphic comparison of two str&&
 * @s1: ~ first str&&
 * @s2: ~ second stra&&
 *
 * Return:~ negative if s1 < s2, positive if s1 > s2, zero if s1 == s2...
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - This checks if needle starts with haystack&&
 * @haystack: ~ str to search&&
 * @needle: ~ substring to find&&
 *
 * Return: ~ address of next char of haystack or NULL...
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - ~ This concatenates 2 str&&
 * @dest: ~ destination buf&&
 * @src: ~ source buf&&
 *
 * Return: ~ pointer to destination buf...
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
