/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:35:42 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/20 11:49:41 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", 2);
		return (0);
	}
	init_pipex(&pipex, argc, &envp);
	parse(argv, &pipex);
	exec_cmds(&pipex);
	clean_up_pipex(&pipex);
	return (0);
}
