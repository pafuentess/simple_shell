#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char *search(list_t *h, char *buff)
{
	list_t *copy;
	char *save;
	copy = h;
	struct stat st;
	while (copy)
	{
		save = str_concat(copy->str, "/");
		save = str_concat(save, buff);
		if (stat(save, &st) == 0)
		{
			lsprintf("FOUND\n");
			break;
		}
		else
		{
			/* Crear lista y comparar*/
		}
		copy = copy->next;
	}
	return (save);
}
/**
* new_process - perfom parent an child procress
* to the shell
* @buff: the input line that user write
* @name: name of program
* Return: 1 if work, -1 if dont work
*/

int new_process(char **buff, char *name, char **env)
{
	pid_t cpid, w;
	int wstatus;
	struct stat st;
	list_t *head;

	if (stat(buff[0], &st) == 0)
		buff[0] = buff[0];
	else
	{
		head = lpath(env);
		buff[0] = search(head, buff[0]);

	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (buff[0] == NULL)
			exit(98);
		else if (execve(buff[0], buff, NULL) == -1)
		{
			perror(name);
			return (-1);
		}
		else
		{
			/* Never */
		}
	}
	else if (cpid < 0)
	perror("Shell");
	else
	{                    /* Code executed by parent */
		do {

			w = waitpid(cpid, &wstatus, WUNTRACED);
			if (w == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
		return (1);
	}
}
