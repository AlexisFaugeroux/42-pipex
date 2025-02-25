/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:35:32 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:13:52 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_parse_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_parse_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_parse_int(int nbr)
{
	char	*str;
	size_t	len;

	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_parse_udec(unsigned int nbr)
{
	char	*str;
	size_t	len;

	str = ft_uitoa(nbr);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_parse_void(void *addr)
{
	unsigned long	addr_long;

	addr_long = (unsigned long)addr;
	if (!addr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		return (ft_parse_hex(addr_long, 'x') + 2);
	}
}
