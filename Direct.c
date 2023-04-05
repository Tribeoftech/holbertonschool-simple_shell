#include "shell.h"
/**
 * dir -  function that opens the directory
 * @argv: The string that is being tested
 * @path_token: Token to be searched
 * @av: the command line
 * @counter: the counter.
 * Return: Dir on succes and NULL otherwise
 */
char *dir(char **argv, char **path_token, char **av, int counter)
{
	struct dirent *dir_store;
	DIR *directory = NULL;
	int i;
	char *exe = NULL, *store = NULL;
	char *format = "%s: %d: %s: not found\n";

	/* Testing to see if its already an executable */
	if (argv[0][0] == '/')
	{
		return (argv[0]);
	}
	/* looping through the path_token */
	for (i = 0; path_token[i] != NULL; i++)
	{
		/* Use Opendir to access all the path directories */
		directory = opendir(path_token[i]);
		if (directory != NULL)
		{
			/* Reading the open directories */
			while ((dir_store = readdir(directory)) != NULL)
			{
				/* If we find a match proceed on with the if loop */
				if (_strcmp(argv[0], dir_store->d_name) == 0)
				{
					store = path_token[i];
					exe = exe_maker(store, argv);
					closedir(directory);
					return (exe);
				}
			}
		}
		else
		{
			fprintf(stderr, format, av[0], counter, argv[0]);
		}
		closedir(directory);
	}
	return (NULL);
}

/**
 * exe_maker - function that helps add a
 * slash to the first string and concat
 * string with the slash
 * @store: the path_token being inputted
 * @argv: the string being inputted
 * Return: The concatted string
 */
char *exe_maker(char *store, char **argv)
{
	char *slash = NULL;
	char *commando = NULL;

	/* Adding a slash to the first string */
	slash = _strcat(store, "/");
	/* Concatenate both slash string and argv string */
	commando = _strcat(slash, argv[0]);

	/* Need to free slash because strcat mallocs */
	free(slash);
	return (commando);
}

/**
 * execute - Function to help with pid
 * process and forking
 * @xecutable:character to execute on
 * @argv: String that is being inputted
 * Return: 0 on success
 */

int execute(char *xecutable, char **argv)
{
	pid_t pid;
	int exit_code;

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed\n");
	}
	if (pid == 0)
	{
		execve(xecutable, argv, environ);
	}
	else
	{
		waitpid(pid, &exit_code, 0);
	}
	exit_code = WEXITSTATUS(exit_code);
	return (exit_code);
}
