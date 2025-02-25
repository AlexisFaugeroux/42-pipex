/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:04:11 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 11:52:34 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	handle_exec_error(t_pipex *pipex, int cmd_index)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(pipex->cmds[cmd_index]->path, 2);
	ft_putstr_fd("\n", 2);
	clean_up_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	handle_fork_error(t_pipex *pipex, int pipe_fd[2])
{
	clean_up_pipex(pipex);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exit(EXIT_FAILURE);
}

void	handle_dup2_error(t_pipex *pipex, int pipe_fd[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	clean_up_pipex(pipex);
	exit(EXIT_FAILURE);
}
