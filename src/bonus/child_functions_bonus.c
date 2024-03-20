/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:56:20 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 12:34:28 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	dup2_in_out(int *new_in, int *new_out, t_variables *t)
{
	if (dup2(*new_in, 0) == -1 || dup2(*new_out, 1) == -1)
	{
		close_pipes(t);
		error_exit("dup2 failed\n", t, 1);
	}
	close(*new_in);
	close(*new_out);
	*new_in = -2;
	*new_out = -2;
}

static void	failed_fork(t_variables *t, int child_ct)
{
	int	i;

	close_pipes(t);
	i = -1;
	while (++i < child_ct)
		waitpid(t->pid[i], NULL, 0);
	error_exit("Failed to fork\n", t, 1);
}

static int	is_awk(char const *s)
{
	while (*s == ' ' || *s == '"' || *s == '\'')
		s++;
	if (!ft_strncmp(s, "awk", 3))
		return (1);
	return (0);
}

static void	get_args(t_variables *t, char **argv)
{
	if (is_awk(argv[2 + t->here_doc + t->cmd_ct]))
		t->args = ft_split3(argv[2 + t->here_doc + t->cmd_ct], ' ');
	else
		t->args = ft_split2(argv[2 + t->here_doc + t->cmd_ct], ' ');
	if (!t->args)
		error_exit("Failed to get arguments\n", t, 4);
}

void	execute_cmd(char **argv, char **envp, t_variables *t, int argc)
{
	t->pid[t->cmd_ct] = fork();
	if (t->pid[t->cmd_ct] < 0)
		failed_fork(t, t->cmd_ct - 1);
	if (t->pid[t->cmd_ct] == 0)
	{
		if (t->cmd_ct == 0)
		{
			open_infile(argv, t);
			dup2_in_out(&t->infile, &t->pipes[1], t);
		}
		else if (t->cmd_ct == t->cmd_amt - 1)
		{
			open_outfile(argv, argc, t);
			dup2_in_out(&t->pipes[2 * t->cmd_ct - 2], &t->outfile, t);
		}
		else
			dup2_in_out(&t->pipes[2 * t->cmd_ct - 2],
				&t->pipes[2 * t->cmd_ct + 1], t);
		close_pipes(t);
		get_args(t, argv);
		t->cmd_path = get_cmd_path(t->args[0], t->paths, t);
		execve(t->cmd_path, t->args, envp);
		error_exit2(t->args[0], t, -1);
	}
}
