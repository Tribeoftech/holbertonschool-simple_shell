#include "shell.h"
/**
 * sh_exit - function that exits
 * @argv: The string being inputted
 * @buffer: The buffer character
 * @poopno: keeps track of exit codes
 * Return: 0 if everything executes properly
 */
int sh_exit(char **argv, char *buffer, int poopno)
{
	free(argv);
	free(buffer);
	exit(poopno);
}
/**
 * sh_env -  function to help with env var
 * Return: 0 if everything executes properly
 */
int sh_env(void)
{
	int line, content;
	char *string = NULL; /* create a placeholder for each line */
	/* loops through the line number of env */
	for (line = 0; environ[line] != NULL; line++)
	{ /* loops through the characters to print that line */
		for (content = 0; environ[line][content] != '\0'; content++)
		{ /* stores into string */
			string = (&(environ[line][content]));
			/* prints with write to std output */
			write(STDOUT_FILENO, string, _strlen(string));
			break;
		}
		_putchar('\n');
	}
	return (0);
}
/**
 * sh_setenv - function to help setenv var
 * @argv: The string being inputted
 * Return: 0 on success
 */
int sh_setenv(char **argv)
{
	argv = argv;
	return (0);
}
/**
 * sh_unsetenv - Function to unset env var
 * @argv: The string being inputted
 * Return: 0 on success
 */
int sh_unsetenv(char **argv)
{
	argv = argv;
	return (0);
}
/**
 * sh_cd - function for cd
 * @argv: the string being inputted
 * Return: 0 on success
 */
int sh_cd(char **argv)
{
	argv = argv;
	return (0);
}
