/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:52:47 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/18 15:29:11 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char const *nptr)
{
	int		i;
	int		sign;
	long	nb;

	nb = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(*(nptr + i)))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(*(nptr + i)) && *(nptr + i))
	{
		nb = (nb * 10) + *(nptr + i) - '0';
		i++;
	}
	return ((int)(sign * nb));
}
