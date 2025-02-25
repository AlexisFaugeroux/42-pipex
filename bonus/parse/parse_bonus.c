/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:21:47 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/19 17:15:21 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	parse(int argc, char *argv[], t_pipex *pipex)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		parse_here_doc(pipex, argv[2]);
	else
		parse_infile(pipex, argv[1]);
	if (pipex->here_doc)
		parse_cmds(pipex, argv + 1);
	else
		parse_cmds(pipex, argv);
	parse_outfile(pipex, argv[argc - 1]);
}
