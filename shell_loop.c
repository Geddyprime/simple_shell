#include "shell.h"

/**
 * hsh - The main shell loop&&
 * @info: ~ parameter & return info struct&&
 * @av: ~ argument vector frm main()&&
 *
 * Return: 0 on success, 1 on error, or error code...
 */
int hsh(info_t *info, char **av)
{
	ssize_t v = 0;
	int builtin_rt = 0;

	while (v != -1 && builtin_rt != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		v = get_input(info);
		if (v != -1)
		{
			set_info(info, av);
			builtin_rt = find_builtin(info);
			if (builtin_rt == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_rt == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_rt);
}

/**
 * find_builtin - This should find a built-in command&&
 * @info: ~ parameter & return info struct&&
 *
 * Return: -1 if built-in not found,
 * 0 if built-in executed successfully,
 * 1 if built-in found but not successful,
 * 2 if built-in signals exit()...
 */
int find_builtin(info_t *info)
{
	int k, built_in_rt = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (k = 0; builtintbl[i].type; k++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_rt = builtintbl[i].func(info);
			break;
		}
	return (built_in_rt);
}

/**
 * find_cmd - This should find a command in PATH&&%
 * @info: ~ parameter & return info struct&&
 *
 * Return: void..
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - This should fork an exec thread to run cmd%%&
 * @info: ~%%parameter & return info struct%%&
 *
 * Return: ~ %%void...
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
