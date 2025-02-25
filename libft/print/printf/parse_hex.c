/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:40:41 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:13:51 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_parse_hex(unsigned long nb, char c)
{
	char			*str;
	size_t			len;

	if (c == 'x')
		str = ft_ulong_itoa_base(nb, FT_HEX_BASE_LOW);
	else
		str = ft_ulong_itoa_base(nb, FT_HEX_BASE_UP);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
