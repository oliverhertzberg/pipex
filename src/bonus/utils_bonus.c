/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:50:04 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 17:39:57 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	malloc_pipes_pid(t_variables *t)
{
	t->pipes = (int *)malloc((t->pipe_amt) * sizeof(int));
	if (!t->pipes)
		error_exit("Malloc for pipes failed\n", t, 1);
	t->pid = (int *)malloc((t->cmd_amt) * sizeof(int));
	if (!t->pid)
		error_exit("Malloc for pid failed\n", t, 1);
}

void	close_free_all(t_variables *t)
{
	close_pipes(t);
	if (t->infile >= 0)
		close(t->infile);
	if (t->outfile >= 0)
		close(t->outfile);
	free(t->pipes);
	if (t->paths)
		free_ptr_arr(t->paths);
}

void	free_ptr_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}
