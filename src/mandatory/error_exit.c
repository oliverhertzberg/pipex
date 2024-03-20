/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:48:14 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/14 12:06:32 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	error_exit(char *error, t_variables *t, int exitcode)
{
	perror(error);
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
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
	exit(errorcode);
}

void	error_exit4(t_variables *t, int exitcode)
{
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
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
	exit(exitcode);
}
