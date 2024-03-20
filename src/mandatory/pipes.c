/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:35:59 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/11 14:04:15 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	create_pipes(t_variables *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < (t->cmd_amt - 1))
	{
		if (pipe(t->pipes + 2 * i) < 0)
		{
			j = 0;
			while (j < i * 2)
				close(t->pipes[j++]);
			free(t->pipes);
			error_exit("Failed to create pipes\n", t, 1);
		}
		i++;
	}
}

void	close_pipes(t_variables *t)
{
	int	i;

	i = 0;
	while (i < t->pipe_amt)
		close(t->pipes[i++]);
}
