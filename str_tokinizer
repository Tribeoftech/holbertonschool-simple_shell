#include "shell.h"
/**
 * tokenizer - function to help tokenize
 * certain variables
 * @input_str: the inputted string
 * Return: argv
 */
char **tokenizer(char *input_str)
{
	int token_inc = 0, token_count = 0, i;
	char **argv;
	char *tokenize;

	strtok(input_str, "\n");
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if (input_str[i] == ' ')
		{
			token_count++;
		}
	}
	argv = malloc(8 * (token_count + 2));

	if (argv == NULL)
	{
		return (NULL);
	}
	else
	{
		tokenize = strtok(input_str, " ");

		while (token_inc < (token_count + 1))
		{
			argv[token_inc] = tokenize;
			tokenize = strtok(NULL, " ");
			token_inc++;
		}
		argv[token_inc] = NULL;
	}
	if (!argv[0])
	{
		free(argv);
		argv = NULL;
	}
	return (argv);
}
