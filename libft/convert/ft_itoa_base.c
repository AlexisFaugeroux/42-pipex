/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:43:28 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:06:47 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_digits(unsigned long nbr, int base_len)
{
	int	digits;

	if (nbr == 0)
		return (1);
	digits = 0;
	while (nbr != 0)
	{
		digits++;
		nbr /= base_len;
	}
	return (digits);
}

static void	ft_write_number(char *res, unsigned long n,
							int digits, char const *base)
{
	size_t const	base_len = ft_strlen(base);

	while (n > 0)
	{
		res[digits - 1] = base[n % base_len];
		n /= base_len;
		--digits;
	}
}

char	*ft_ulong_itoa_base(unsigned long nbr, char const *base_to)
{
	int		digits;
	char	*res;

	digits = ft_get_digits(nbr, ft_strlen(base_to));
	res = (char *)malloc((sizeof(char) * (digits + 1)));
	if (!res)
		return (NULL);
	if (nbr == 0)
	{
		res[0] = base_to[0];
		res[1] = '\0';
		return (res);
	}
	res[digits] = '\0';
	ft_write_number(res, nbr, digits, base_to);
	return (res);
}
