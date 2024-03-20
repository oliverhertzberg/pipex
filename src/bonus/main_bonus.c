/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:48:16 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 17:40:05 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	init_t_variables(t_variables *t, char **envp, char **argv)
{
	t->here_fd = -2;
	t->infile = -2;
	t->outfile = -2;
	t->pipes = NULL;
	t->pid = NULL;
	t->args = NULL;
	t->cmd_path = NULL;
	if (!ft_strncmp(argv[1], "here_doc", 9))
		t->here_doc = 1;
	else
		t->here_doc = 0;
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

	if (argc == 1
		|| (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6) || argc < 5)
		return (write(2, "Argument error!\n", 17), EXIT_FAILURE);
	init_t_variables(&t, envp, argv);
	t.cmd_amt = argc - 3 - t.here_doc;
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
	if (access(".here_doc", F_OK) == 0)
		unlink(".here_doc");
	free(t.pid);
	return (WEXITSTATUS(t.status));
}
