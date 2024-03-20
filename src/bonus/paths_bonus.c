/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:51:48 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 19:05:23 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

char	*get_path(char **envp)
{
	if (!envp)
		return (NULL);
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp == NULL)
		return (NULL);
	return (*envp + 5);
}

static	int	is_file(char *command)
{
	if (!command)
		return (0);
	if (ft_strchr(command, '/') != NULL)
		return (1);
	return (0);
}

static char	*cmd_file_bin(char *cmd, t_variables *t, char **paths)
{
	if (!paths && access(cmd, F_OK) != 0)
		error_exit3(cmd, " No such file or directory\n", t, 127);
	if (access(cmd, F_OK) != 0)
	{
		if (is_file(cmd))
			error_exit3(cmd, " No such file or directory\n", t, 127);
		else
			error_exit3(cmd, " command not found\n", t, 127);
	}
	if (is_file(cmd))
	{
		if (access(cmd, X_OK) != 0)
			error_exit3(cmd, " Permission denied\n", t, 126);
		else
			return (cmd);
	}
	error_exit3(cmd, " command not found\n", t, 127);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **paths, t_variables *t)
{
	char	*temp;
	char	*cmd_path;

	while (paths != NULL && *paths)
	{
		temp = ft_strjoin(*paths, "/");
		cmd_path = ft_strjoin(temp, cmd);
		free (temp);
		if (!cmd_path)
			error_exit3(cmd, " command not found\n", t, 127);
		if (access(cmd_path, F_OK) == 0)
		{
			if (access(cmd_path, X_OK) == 0)
				return (cmd_path);
			error_exit3(cmd, " permission denied\n", t, 126);
		}
		free (cmd_path);
		paths++;
	}
	if (cmd_file_bin(cmd, t, paths) != NULL)
		return (cmd);
	error_exit3(t->args[0], " No such file or directory\n", t, 127);
	return (NULL);
}
