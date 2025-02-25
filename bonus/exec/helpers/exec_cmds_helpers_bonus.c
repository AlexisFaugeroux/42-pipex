/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:04:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 13:57:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

void	create_pipes(t_pipex *pipex)
{
	int	i;
	int	nb_pipes;

	nb_pipes = pipex->nb_cmds - 1;
	pipex->pipes_fd = (int **)malloc(sizeof(int *)
			* (nb_pipes + sizeof(int *)));
	if (!pipex->pipes_fd)
		handle_malloc_error(pipex);
	pipex->pipes_fd[nb_pipes] = 0;
	i = 0;
	while (i < nb_pipes)
	{
		pipex->pipes_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->pipes_fd[i])
			handle_malloc_error(pipex);
		if (pipe(pipex->pipes_fd[i]) == -1)
		{
			perror("pipe");
			clean_up_pipex(pipex);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_pipes(int	**pipes, int size)
{
	int	i;

	if (pipes)
	{
		i = 0;
		while (i < size)
		{
			close(pipes[i][0]);
			close(pipes[i][1]);
			i++;
		}
	}
}
