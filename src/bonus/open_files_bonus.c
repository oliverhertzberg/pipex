/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:58:28 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 12:40:52 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	open_infile(char **argv, t_variables *t)
{
	if (t->here_doc == 1)
		get_here_doc(argv[2], t);
	else
	{
		t->infile = open(argv[1], O_RDONLY);
		if (t->infile < 0)
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": ", 2);
			perror("");
			close_pipes(t);
			error_exit4(t, 1);
		}
	}
}

void	open_outfile(char **argv, int argc, t_variables *t)
{
	if (t->here_doc == 1)
		t->outfile = open (argv[argc - 1], O_APPEND | O_CREAT | O_RDWR, 0644);
	else
		t->outfile = open (argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (t->outfile < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[argc - 1], 2);
		ft_putstr_fd(": ", 2);
		perror("");
		close_pipes(t);
		error_exit4(t, 1);
	}
}
