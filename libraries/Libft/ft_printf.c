/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:11:30 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:42:57 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ident_sep(const char *a, va_list arg)
{
	char	c;

	c = a[1];
	if (c == 'c')
		return (is_chr((char)va_arg(arg, int)));
	if (c == 's')
		return (is_str((char *)va_arg(arg, char *)));
	if (c == 'p')
		return (is_p((unsigned long)va_arg(arg, unsigned long)));
	if (c == 'd' || c == 'i')
		return (is_d((int)va_arg(arg, int)));
	if (c == 'u')
		return (is_u((unsigned int)va_arg(arg, unsigned int)));
	if (c == 'x')
		return (is_x((unsigned int)va_arg(arg, unsigned int)));
	if (c == 'X')
		return (is_xup((unsigned int)va_arg(arg, unsigned int)));
	if (c == '%')
		return (write(1, "\%", 1));
	return (0);
}

int	ft_printf(const char *a, ...)
{
	int		i;
	int		ret;
	int		count;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, a);
	while (a[i])
	{
		if (a[i] != '%')
			ret = write(1, &(a[i++]), 1);
		else
		{
			ret = ident_sep(a + i, arg);
			i += 2;
		}
		if (ret == -1)
		{
			return (-1);
		}
		count += ret;
	}
	va_end(arg);
	return (count);
}
