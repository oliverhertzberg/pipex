/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:48:16 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 12:42:51 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	init_t_variables(t_variables *t, char **envp)
{
	t->infile = -2;
	t->outfile = -2;
	t->paths = NULL;
	t->pipes = NULL;
	t->pid = NULL;
	t->args = NULL;
	t->cmd_path = NULL;
	t->path_string = get_path(envp);
	if (t->path_string != NULL)
	{
		t->paths = ft_split(t->path_string, ':');
		if (!t->paths)
			error_exit("init_t_variables ft_split malloc failed\n", t, 1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_variables	t;

	if (argc != 5)
		return (write(2, "Argument error!\n", 17), EXIT_FAILURE);
	init_t_variables(&t, envp);
	t.cmd_amt = argc - 3;
	t.pipe_amt = (t.cmd_amt - 1) * 2;
	malloc_pipes_pid(&t);
	create_pipes(&t);
	t.cmd_ct = -1;
	while (++t.cmd_ct < t.cmd_amt)
		execute_cmd(argv, envp, &t, argc);
	close_free_all(&t);
	t.cmd_ct = -1;
	while (++t.cmd_ct < t.cmd_amt)
		waitpid(t.pid[t.cmd_ct], &t.status, 0);
	free(t.pid);
	return (WEXITSTATUS(t.status));
}
