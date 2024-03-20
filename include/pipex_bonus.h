/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:47:45 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/03/15 12:30:50 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_variables
{
	int		infile;
	int		outfile;
	int		*pipes;
	int		pipe_amt;
	int		cmd_amt;
	int		cmd_ct;
	int		here_doc;
	int		here_fd;
	int		status;
	pid_t	wpid;
	pid_t	*pid;
	char	*path_string;
	char	**paths;
	char	*cmd_path;
	char	**args;
}	t_variables;

void	dup2_in_out(int *new_in, int *new_out, t_variables *t);
void	execute_cmd(char **argv, char **envp, t_variables *t, int argc);
void	get_here_doc(char *argv, t_variables *t);
void	init_t_variables(t_variables *t, char **envp, char **argv);
void	open_infile(char **argv, t_variables *t);
void	open_outfile(char **argv, int argc, t_variables *t);
char	*get_path(char **envp);
char	*get_cmd_path(char *cmd, char **paths, t_variables *t);
void	create_pipes(t_variables *t);
void	close_pipes(t_variables *t);
void	malloc_pipes_pid(t_variables *t);
void	error_exit(char *error, t_variables *t, int errorcode);
void	error_exit2(char *s, t_variables *t, int errorcode);
void	error_exit3(char *cmd, char *s, t_variables *t, int errorcode);
void	error_exit4(t_variables *t, int exitcode);
void	close_free_all(t_variables *t);
void	free_ptr_arr(char **s);

#endif