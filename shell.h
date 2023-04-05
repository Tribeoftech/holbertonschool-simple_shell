#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

/** Global calling var**/
extern char **environ;

/** Helper Functions for String **/
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

char **_getenv(char *env);
int _putchar(char c);
char *concat_all(char *name, char *sep, char *value);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **tokenizer(char *input_str);
char *grab_name(char *full_line);
char **env_tokenizer(char *input_str);
int func_finder(char **argv, char *buffer, int poopno);
int sh_exit(char **argv, char *buffer, int poopno);

/** Shell Helper **/
int sh_env(void);
int sh_setenv(char **argv);
int sh_unsetenv(char **argv);
int sh_cd(char **argv);
int sh_alias(char **argv);

void everything_free(char **pointer_array);
int execute(char *xecutable, char **argv);
void _puts(char *str);

char *dir(char **argv, char **path_token, char **av, int counter);
char *exe_maker(char *store, char **argv);

/**
 * struct builtins - struct to handle builtins
 * @argv: The string
 * @func: The corresponding function
 */
typedef struct builtins
{
	char *argv;
	int (*func)();
} builtins;

#endif /* SHELL_H */
