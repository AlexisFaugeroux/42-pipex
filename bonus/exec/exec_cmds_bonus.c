/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:08 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 14:00:57 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static void	handle_routing_incoming(t_pipex *pipex, int index)
{
	if (index == 0)
	{
		if (dup2(pipex->fd_infile, STDIN_FILENO) == -1)
			handle_dup2_error(pipex);
	}
	else
		if (dup2(pipex->pipes_fd[index - 1][0], STDIN_FILENO) == -1)
			handle_dup2_error(pipex);
}

static void	handle_routing_outgoing(t_pipex *pipex, int index)
{
	if (index == pipex->nb_cmds - 1)
	{
		if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
			handle_dup2_error(pipex);
	}
	else
		if (dup2(pipex->pipes_fd[index][1], STDOUT_FILENO) == -1)
			handle_dup2_error(pipex);
}

static void	handle_child_process(t_pipex *pipex, int index)
{
	if (pipex->pipes_fd && pipex->cmds[index])
	{
		handle_routing_incoming(pipex, index);
		handle_routing_outgoing(pipex, index);
		close_pipes(pipex->pipes_fd, pipex->nb_cmds - 1);
		if (execve(pipex->cmds[index]->path,
				pipex->cmds[index]->args,
				NULL) == -1)
			handle_exec_error(pipex, index);
	}
	else
	{
		clean_up_pipex(pipex);
		exit(EXIT_SUCCESS);
	}
}

void	exec_cmds(t_pipex *pipex)
{
	int		i;

	create_pipes(pipex);
	pipex->pids = (int *)malloc(sizeof(int) * pipex->nb_cmds);
	if (!pipex->pids)
	{
		perror("malloc");
		clean_up_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < pipex->nb_cmds)
	{
		pipex->pids[i] = fork();
		if (pipex->pids[i] == -1)
			handle_fork_error(pipex, pipex->pids);
		if (pipex->pids[i] == 0)
			handle_child_process(pipex, i);
		i++;
	}
	close_pipes(pipex->pipes_fd, pipex->nb_cmds - 1);
	i = -1;
	while (++i < pipex->nb_cmds)
		waitpid(pipex->pids[i], NULL, 0);
}
