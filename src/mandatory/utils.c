/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:50:04 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/11 14:33:04 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
	close(t->infile);
	close(t->outfile);
	if (t->pipes)
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
