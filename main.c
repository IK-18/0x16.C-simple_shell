#include "shell.h"

/**
 * main - entry point for the shell.
 * @argc: number of arguments supplied to the program.
 * @argv: array of pointers to the arguments.
 *
 * Return: return value of the last executed command.
 */
int main(int argc, char *argv[])
{
	int ret = 0, retn;
	int *exe_ret = &retn;
	char *prompt = "$ ", *new_line = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, handle_signal);

	*exe_ret = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);

	if (argc != 1)
	{
		ret = file_comnd_fle_proc(argv[1], exe_ret);
		free_env();
		als_free_list(aliases);
		return (*exe_ret);
	}

	if (!isatty(STDIN_FILENO))
	{
		while (ret != E_OF_F && ret != EXIT)
			ret = handle_args(exe_ret);
		free_env();
		als_free_list(aliases);
		return (*exe_ret);
	}

	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = handle_args(exe_ret);
		if (ret == E_OF_F || ret == EXIT)
		{
			if (ret == E_OF_F)
				write(STDOUT_FILENO, new_line, 1);
			free_env();
			als_free_list(aliases);
			exit(*exe_ret);
		}
	}

	free_env();
	als_free_list(aliases);
	return (*exe_ret);
}
