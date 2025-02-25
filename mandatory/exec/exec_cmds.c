/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:05:08 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/24 18:43:43 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	handle_write_process(t_pipex *pipex, int pipe_fd[2])
{
	if (pipex->fd_infile > 0 && pipex->cmds[0])
	{
		close(pipe_fd[0]);
		close(pipex->fd_outfile);
		if (dup2(pipex->fd_infile, STDIN_FILENO) == -1)
			handle_dup2_error(pipex, pipe_fd);
		close(pipex->fd_infile);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			handle_dup2_error(pipex, pipe_fd);
		close(pipe_fd[1]);
		if (execve(pipex->cmds[0]->path, pipex->cmds[0]->args, NULL) == -1)
			handle_exec_error(pipex, 0);
	}
	else
	{
		clean_up_pipex(pipex);
		exit(EXIT_SUCCESS);
	}
}

static void	handle_read_process(t_pipex *pipex, int pipe_fd[2])
{
	if (pipex->cmds[1])
	{
		close(pipe_fd[1]);
		close(pipex->fd_infile);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			handle_dup2_error(pipex, pipe_fd);
		close(pipe_fd[0]);
		if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
			handle_dup2_error(pipex, pipe_fd);
		close(pipex->fd_outfile);
		if (execve(pipex->cmds[1]->path, pipex->cmds[1]->args, NULL) == -1)
			handle_exec_error(pipex, 1);
	}
	{
		clean_up_pipex(pipex);
		exit(EXIT_SUCCESS);
	}
}

void	exec_cmds(t_pipex *pipex)
{
	int		pipe_fd[2];
	int		pid1;
	int		pid2;

	if (pipe(pipe_fd) == -1)
	{
		clean_up_pipex(pipex);
		exit(EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == -1)
		handle_fork_error(pipex, pipe_fd);
	if (pid1 == 0)
		handle_write_process(pipex, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		handle_fork_error(pipex, pipe_fd);
	if (pid2 == 0)
		handle_read_process(pipex, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (wait(NULL) > 0)
		;
}
