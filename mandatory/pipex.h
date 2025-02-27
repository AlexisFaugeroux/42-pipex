/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:36:51 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/27 10:30:21 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char	*path;
	char	**args;
}				t_cmd;

typedef struct s_pipex
{
	int		fd_infile;
	int		fd_outfile;
	char	**env_path;
	t_cmd	**cmds;
	int		nb_cmds;
}				t_pipex;

// cmds
void	exec_cmds(t_pipex *pipex);
//	helpers
void	handle_exec_error(t_pipex *pipex, int cmd_index);
void	handle_fork_error(t_pipex *pipex, int pipe_fd[2]);
void	handle_dup2_error(t_pipex *pipex, int pipe_fd[2]);

// parse
void	parse(char *argv[], t_pipex *pipex);
void	parse_infile(t_pipex *pipex, char *input);
void	parse_outfile(t_pipex *pipex, char *input);
void	parse_cmds(t_pipex *pipex, char *argv[]);
//	 helpers
char	*get_env_path(char **envp);
char	*get_path(char *env_path, char *cmd);
char	*get_path_wdir(char *cmd);
char	**ft_split_quotes(char const *s, char c);
void	set_quote(char c, char *quote);
int		get_quotes_nb(char *s);
bool	is_successive_quotes(const char *s, int i, int j);
char	*remove_quotes(char *s);
void	ft_free_split(char **split, int i);
bool	skip_sep(const char *s, char sep, int *i);

// clean
void	clean_up_pipex(t_pipex *pipex);
void	free_cmd(t_cmd *cmd);
void	free_paths(char **paths, int index);

#endif
