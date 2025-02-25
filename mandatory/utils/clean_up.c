/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:15:02 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 11:49:26 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
	if (pipex->fd_infile > -1)
		close(pipex->fd_infile);
	if (pipex->fd_outfile > -1)
		close(pipex->fd_outfile);
}
