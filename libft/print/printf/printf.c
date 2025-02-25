/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:05:23 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/17 19:13:52 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_parse(va_list args, char c)
{
	if (c == 'c')
		return (ft_parse_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_parse_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_parse_void(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_parse_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_parse_udec(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_parse_hex((unsigned int)va_arg(args, int), c));
	return (-1);
}

static void	ft_write(va_list args, char const *s, int *count)
{
	unsigned int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != '%')
		{
			ft_putchar_fd(*(s + i), 1);
			(*count)++;
			i++;
		}
		else if (*(s + i) == '%' && *(s + i + 1) == '%')
		{
			ft_putchar_fd(*(s + i), 1);
			(*count)++;
			i += 2;
		}
		else
		{
			*count += ft_parse(args, *(s + i + 1));
			i += 2;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	if (s == NULL || (*s == '%' && !*(s + 1)))
		return (-1);
	va_start(args, s);
	count = 0;
	ft_write(args, s, &count);
	va_end(args);
	return (count);
}
