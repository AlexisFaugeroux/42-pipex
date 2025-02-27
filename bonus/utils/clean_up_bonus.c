/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:15:02 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/27 11:34:43 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_paths(char **paths, int index)
{
	int	i;
	int	size;

	size = 0;
	while (paths[size])
		size++;
	if (index >= 0)
		i = index;
	else
		i = size - 1;
	if (paths)
	{
		while (i >= 0)
		{
			free(paths[i]);
			i--;
		}
		free(paths);
	}
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	if (cmd)
	{
		if (cmd->path)
			free(cmd->path);
		if (cmd->args)
		{
			i = 0;
			while (cmd->args[i])
			{
				free(cmd->args[i]);
				i++;
			}
			free(cmd->args);
		}
		free(cmd);
	}
}

void	clean_pipes(t_pipex *pipex)
{
	int	i;

	if (pipex->pipes_fd)
	{
		i = 0;
		while (i < (pipex->nb_cmds - 1))
		{
			if (pipex->pipes_fd[i])
			{
				close(pipex->pipes_fd[i][0]);
				close(pipex->pipes_fd[i][1]);
				free(pipex->pipes_fd[i]);
			}
			i++;
		}
		free(pipex->pipes_fd);
	}
}

void	clean_fds(t_pipex *pipex)
{
	if (pipex->fd_infile > -1)
	{
		if (pipex->here_doc)
			unlink("here_doc.tmp");
		close(pipex->fd_infile);
	}
	if (pipex->fd_outfile > -1)
		close(pipex->fd_outfile);
}

void	clean_up_pipex(t_pipex *pipex)
{
	int	i;

	if (pipex->cmds)
	{
		i = 0;
		while (i < (pipex->nb_cmds))
		{
			if (pipex->cmds[i])
				free_cmd(pipex->cmds[i]);
			i++;
		}
		free(pipex->cmds);
	}
	clean_pipes(pipex);
	clean_fds(pipex);
	if (pipex->pids)
		free(pipex->pids);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	close(STDERR_FILENO);
}
