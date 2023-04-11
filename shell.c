#include "shell.h"

/**
 * main - prints the shell
 * @ac: void.
 * @av: the orginal argument for shell.
 * Return: zero.
 */
int main(int ac, char **av)
{
	char *money_sign = "$ ";
	char *buffer = NULL;
	char **argv, **path_tokens;
	char *xcuteable;
	size_t buffer_length = 0;
	int counter = 0, uhoh = 0;
	/*ssize_t userinput;*/
	(void)ac;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, money_sign, _strlen(money_sign));
		if (getline(&buffer, &buffer_length, stdin) == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(buffer), exit(uhoh);
		}
		counter++;
		if (buffer == NULL)
			exit(0);
		argv = tokenizer(buffer);
		if (argv == NULL || argv[0] == NULL)
			continue;
		if (func_finder(argv, buffer, uhoh) == 1)
		{
			free(argv);
			continue;
		}
		path_tokens = _getenv("PATH");
		xcuteable = dir(argv, path_tokens, av, counter);
		if (xcuteable != NULL)
			uhoh = execute(xcuteable, argv);
		if (argv[0][0] != '/')
			free(xcuteable);
		everything_free(path_tokens);
		free(argv);
	}
	free(argv), free(buffer);
	return (zero);
}
