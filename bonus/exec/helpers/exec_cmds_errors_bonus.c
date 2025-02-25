/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_errors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:32:34 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 11:54:15 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex_bonus.h"

void	handle_exec_error(t_pipex *pipex, int cmd_index)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(pipex->cmds[cmd_index]->path, 2);
	ft_putstr_fd("\n", 2);
	clean_up_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	handle_fork_error(t_pipex *pipex, int *pids)
{
	perror("fork");
	free(pids);
	clean_up_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	handle_dup2_error(t_pipex *pipex)
{
	perror("dup2");
	clean_up_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	handle_malloc_error(t_pipex *pipex)
{
	perror("malloc");
	clean_up_pipex(pipex);
	exit(EXIT_FAILURE);
}
