/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:50:59 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:13:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_base_fd(int nbr, char const *base, int fd)
{
	int const	base_len = ft_strlen(base);
	long		n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > base_len - 1)
		ft_putnbr_base_fd(n / base_len, base, fd);
	ft_putchar_fd(base[n % base_len], fd);
}

void	ft_putnbr_long_base_fd(long nbr, char const *base, int fd)
{
	int const	base_len = ft_strlen(base);
	long long	n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > base_len - 1)
		ft_putnbr_long_base_fd(n / base_len, base, fd);
	ft_putchar_fd(base[n % base_len], fd);
}

void	ft_putnbr_ulong_base_fd(unsigned long nbr, char const *base, int fd)
{
	size_t const	base_len = ft_strlen(base);

	if (nbr > base_len - 1)
		ft_putnbr_ulong_base_fd(nbr / base_len, base, fd);
	ft_putchar_fd(base[nbr % base_len], fd);
}
