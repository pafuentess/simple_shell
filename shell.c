#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

/**
* main - execute the shell
* @argc: number of arguemnts
* @argv: store the arguments
* Return: if it works
*/

int main(int argc, char **argv, char **env)
{
	char *newpath;
	char *buffer;
	char **args;
	int status;
	int count = 0;
	char msn[] = "#cisfun$ ";

	argc = argc;
	argv[1] = argv[1];
	while (msn[count])
		count++;
	while (1)
	{
		write(STDOUT_FILENO, msn, count);
		buffer = get_line();
		args = tokenizar(buffer, " \t\n\r");
		status = new_process(args, argv[0], NULL);
	}

	write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(status);
}
