/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:21:47 by afaugero          #+#    #+#             */
/*   Updated: 2025/02/17 16:20:52 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	parse(char *argv[], t_pipex *pipex)
{
	parse_infile(pipex, argv[1]);
	parse_cmds(pipex, argv);
	parse_outfile(pipex, argv[4]);
}
