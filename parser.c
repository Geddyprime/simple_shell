#include "shell.h"

/**
 * is_cmd - ~This should determine if a file is an executable command%%&
 * @info: ~%%info struct%%&
 * @path: ~%%path to the file%%&
 *
 * Return: 1 if true, 0 otherwise...
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - ~ %%This should duplicates chars%%&
 * @pathstr: ~ %%PATH str%%&
 * @start: ~ %%starting index%%&
 * @stop: ~%%stopping index%%&
 *
 * Return: pointer to new buf...
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int j = 0, q = 0;

	for (q = 0, j = start; j < stop; j++)
		if (pathstr[j] != ':')
			buf[q++] = pathstr[j];
	buf[q] = 0;
	return (buf);
}

/**
 * find_path - %%This should find the cmd in the PATH str%%$
 * @info: ~ %%$info struct%%$
 * @pathstr: ~ $PATH str%%$
 * @cmd: %%$cmd to find%%$
 *
 * Return: ~ $full path of cmd if found or NULL...
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int j = 0, cur_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[j] || pathstr[j] == ':')
		{
			path = dup_chars(pathstr, cur_pos, j);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[j])
				break;
			cur_pos = j;
		}
		j++;
	}
	return (NULL);
}
