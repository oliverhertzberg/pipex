/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:48:14 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 12:28:56 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	error_exit(char *error, t_variables *t, int exitcode)
{
	perror(error);
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
	if (t->here_fd >= 0)
		close(t->here_fd);
	if (t->paths)
		free_ptr_arr(t->paths);
	if (t->pid)
		free(t->pid);
	if (t->pipes)
		free(t->pipes);
	if (t->cmd_path)
		free(t->cmd_path);
	if (t->args)
		free(t->args);
	if (access(".here_doc", F_OK) == 0)
		unlink(".here_doc");
	exit(exitcode);
}

void	error_exit2(char *s, t_variables *t, int errorcode)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(s, 2);
	perror(" ");
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
	if (t->here_fd >= 0)
		close(t->here_fd);
	if (t->paths)
		free_ptr_arr(t->paths);
	if (t->pid)
		free(t->pid);
	if (t->pipes)
		free(t->pipes);
	if (t->cmd_path)
		free(t->cmd_path);
	if (t->args)
		free(t->args);
	if (access(".here_doc", F_OK) == 0)
		unlink(".here_doc");
	exit(errorcode);
}

void	error_exit3(char *cmd, char *s, t_variables *t, int errorcode)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(":", 2);
	ft_putstr_fd(s, 2);
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
	if (t->here_fd >= 0)
		close(t->here_fd);
	if (t->paths)
		free_ptr_arr(t->paths);
	if (t->pid)
		free(t->pid);
	if (t->pipes)
		free(t->pipes);
	if (t->cmd_path)
		free(t->cmd_path);
	if (t->args)
		free(t->args);
	if (access(".here_doc", F_OK) == 0)
		unlink(".here_doc");
	exit(errorcode);
}

void	error_exit4(t_variables *t, int exitcode)
{
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
	if (t->here_fd >= 0)
		close(t->here_fd);
	if (t->paths)
		free_ptr_arr(t->paths);
	if (t->pid)
		free(t->pid);
	if (t->pipes)
		free(t->pipes);
	if (t->cmd_path)
		free(t->cmd_path);
	if (t->args)
		free(t->args);
	if (access(".here_doc", F_OK) == 0)
		unlink(".here_doc");
	exit(exitcode);
}
