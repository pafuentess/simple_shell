#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* struct list - Struct list
* @str: string to store
* @next: next position
* @fun: name of function
*/


typedef struct list
{
	char *str;
	int (*fun)(char *, char **, char **, int);
	struct list *next;

} list_t;

char *oldpwd, *newpwd, *tmppwd;

int _strlen(char *s);
int _putchar(char c);
int ops_exit(char *name, char **buff, char **env, int interactions);
int ops_env(char *name, char **buff, char **env, int interactions);
int ops_cd(char *name, char **buff, char **env, int interactions);
int ops_help(char *name, char **buff, char **env, int interactions);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
char *get_line(void);
char *_getenv(char *key, char **env);
int _path(char **env);
list_t *lpath(char **env);
list_t *add_node_end(list_t **head, char *str);
size_t print_list(const list_t *h);
char **tokenizar(char *buff, char *special);
int _setenv(const char *name, const char *value, int overwrite);
int new_process(char **buff, char **env, int interactions, char *name);
int search(char **buff, char **env, int interactions, char *name);
int _atoi(char *s);
char *_itoi(int interac, char *str);
void free_grid(char **grid);
void free_list(list_t *head);
#endif
