/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:35:42 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 11:56:43 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	init_pipex(t_pipex *pipex, int argc, char ***envp)
{
	pipex->fd_infile = -1;
	pipex->fd_outfile = -1;
	if (!envp || !(*envp) || !(**envp))
		pipex->env_path = NULL;
	else
		pipex->env_path = *envp;
	pipex->nb_cmds = argc - 3;
	pipex->cmds = NULL;
	pipex->pipes_fd = NULL;
	pipex->pids = NULL;
	pipex->here_doc = false;
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Too few arguments\n", 2);
		return (0);
	}
	init_pipex(&pipex, argc, &envp);
	parse(argc, argv, &pipex);
	exec_cmds(&pipex);
	clean_up_pipex(&pipex);
	return (0);
}
