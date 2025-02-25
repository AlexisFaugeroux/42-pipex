/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:34:52 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:06:49 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0 || n == 0)
		digits++;
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static void	write_tab(char *res, int n, int digits)
{
	long	nb;

	res[digits] = '\0';
	nb = n;
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		res[digits -1] = nb % 10 + '0';
		nb /= 10;
		digits--;
	}
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*res;

	digits = get_digits(n);
	res = (char *)malloc(sizeof(char) * (digits + 1));
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	write_tab(res, n, digits);
	return (res);
}
