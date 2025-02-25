/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:22:29 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:13:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nb;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		nb = n + '0';
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n < 10)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_putunbr_fd(n / 10, fd);
		ft_putunbr_fd(n % 10, fd);
	}
}

void	ft_putnbr_long_fd(long n, int fd)
{
	long long	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln <= 9)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_long_fd(ln / 10, fd);
		ft_putnbr_long_fd(ln % 10, fd);
	}
}

void	ft_putnbr_ulong_fd(unsigned long n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_ulong_fd(n / 10, fd);
		ft_putnbr_ulong_fd(n % 10, fd);
	}
}
