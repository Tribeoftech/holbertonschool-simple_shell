#include "shell.h"

/**
 * _puts - prints a string
 * @str: pointer to string
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _strcmp -  compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 *
 *
 * Return: The strings compared.
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 && (*s1 == *s2); s1++, s2++)
	{
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

/**
 * everything_free - function to free
 * everything
 * @pointer_array: Char pointing at the array being tested
 * Return: Void
 */
void everything_free(char **pointer_array)
{
	int i = 0;

	while (pointer_array[i] != NULL)
	{
		free(pointer_array[i]);
		i++;
	}
	free(pointer_array);
}
/**
 * _strcat - concatenates two strings
 * @dest: First string.
 * @src: Second string.
 * Return: Dest.
 */

char *_strcat(char *dest, char *src)
{
	int i, j, x;
	char *new = NULL;

	for (j = 0; dest[j] != '\0'; j++)
	{
	}
	for (i = 0; src[i] != '\0'; i++)
	{
	}
	new = malloc(sizeof(char) * (i + j + 1));
	for (x = 0; x < j; x++)
	{
		new[x] = dest[x];
	}
	for (x = 0; x < i; x++)
	{
		new[x + j] = src[x];
	}
	new[x + j] = '\0';
	return (new);
}
