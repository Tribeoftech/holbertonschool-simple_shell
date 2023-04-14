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
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)`
