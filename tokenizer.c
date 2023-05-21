#include "shell.h"

/**
 * **strtow - ~This splits a str into words. Repeated delimiters are ignored&&
 * @str: ~input str&&
 * @d: ~delimeter str&&
 * Return: a pointer to an arr of strings, or NULL on failure...
 */

char **strtow(char *str, char *d)
{
	int i, q, k, n, numword = 0;
	char **z;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numword++;

	if (numword == 0)
		return (NULL);
	z = malloc((1 + numwords) * sizeof(char *));
	if (!z)
		return (NULL);
	for (i = 0, q = 0; q < numword; q++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		z[q] = malloc((k + 1) * sizeof(char));
		if (!z[q])
		{
			for (k = 0; k < q; k++)
				free(z[k]);
			free(z);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			z[q][n] = str[i++];
		z[q][n] = 0;
	}
	z[q] = NULL;
	return (z);
}

/**
 * **strtow2 - ~This splits a str into words&&
 * @str: ~input str&&
 * @d: ~delimeter&&
 * Return:~pointer to an array of strings, or NULL on failure...
 */
char **strtow2(char *str, char d)
{
	int i, q, k, n, numword = 0;
	char **z;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numword++;
	if (numword == 0)
		return (NULL);
	z = malloc((1 + numword) * sizeof(char *));
	if (!z)
		return (NULL);
	for (i = 0, q = 0; q < numword; q++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		z[q] = malloc((k + 1) * sizeof(char));
		if (!z[q])
		{
			for (k = 0; k < q; k++)
				free(z[k]);
			free(z);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			z[q][n] = str[i++];
		z[q][n] = 0;
	}
	z[q] = NULL;
	return (z);
}
