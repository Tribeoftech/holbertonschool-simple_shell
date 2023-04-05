#include "shell.h"
/**
 * _getenv -  function that gets value of
 * env variable by its input
 * @env: env var being inputted
 * Return: Val of Env val
 */
char **_getenv(char *env)
{
	int content, line;
	char *name = NULL;
	/* iterate each line in the environment */
	for (line = 0; environ[line] != NULL; line++)
	{ /* iterate each letter until we see a = */
		for (content = 0; environ[line][content] != '='; content++)
		{
			if (environ[line][content] != env[content])
			{
				break;
			} /* check that this env var name is what we're looking for */
			if (environ[line][content] == env[content])
			{ /* we've hit the end of our search string */
				if (env[content + 1] == '\0' &&
				    environ[line][content + 1] == '=')
				{ /* duplicate everything past the equals */
					name = _strdup(
						&(environ[line][content + 2]));
					return (env_tokenizer(
						name)); /* parse and return */
				}
			}
		}
	}
	return (NULL);
}
/**
 * env_tokenizer - function that tokenizes the
 * string and specific parameters.
 * @input_str: The string that is inputted
 * Return: Env Token on success, NULL otherwise
 */
char **env_tokenizer(char *input_str)
{
	int i;
	int token_inc = 0, token_count = 0;
	char **env_tokens = NULL;
	char *tokenize = NULL;

	token_count = 0;
	for (i = 0; input_str[i] != '\0'; i++)
	{
		if (input_str[i] == ':')
		{
			token_count++;
		}
	}

	env_tokens = malloc(8 * (token_count + 3));

	if (env_tokens == NULL)
	{
		return (NULL);
	}
	else
	{
		tokenize = strtok(input_str, ":");

		while (token_inc < (token_count + 1))
		{
			env_tokens[token_inc] = _strdup(tokenize);
			tokenize = strtok(NULL, ":");
			token_inc++;
		}
		env_tokens[token_count + 1] = NULL;
	}
	free(input_str);
	return (env_tokens);
}
