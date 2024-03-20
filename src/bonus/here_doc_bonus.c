/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:38:47 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/14 13:04:47 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	get_here_doc(char *argv, t_variables *t)
{
	char	*buf;

	t->here_fd = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (t->here_fd < 0)
		error_exit("Failed to create here_doc\n", t, 1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (!buf)
			break ;
		if (buf < 0)
			error_exit("get_next_line failed\n", t, 1);
		if (!ft_strncmp(buf, argv, ft_strlen(argv))
			&& buf[ft_strlen(argv)] == '\n')
			break ;
		write(t->here_fd, buf, ft_strlen(buf));
		free (buf);
	}
	if (buf)
		free (buf);
	close (t->here_fd);
	t->infile = open(".here_doc", O_RDONLY);
	if (t->infile < 0)
		error_exit("Failed to open here_doc\n", t, 1);
}
