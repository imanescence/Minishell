/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:16:58 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:43:18 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnb_rec_u(unsigned int nb, int *count)
{
	unsigned int	b;
	int				ret;

	*count = 0;
	b = nb;
	while (nb > 9)
	{
		b = nb % 10;
		ret = ft_putnb_rec_u(nb / 10, count);
		if (ret == -1)
			return (-1);
		nb = ret;
	}
	b = '0' + b;
	ret = write(1, &b, 1);
	if (ret == -1)
		return (-1);
	*count += ret;
	return (nb);
}

int	is_u(unsigned int nb)
{
	int	*count;
	int	a;
	int	ret;

	count = ft_calloc(sizeof(int), 1);
	if (!count)
		return (-1);
	ret = ft_putnb_rec_u(nb, count);
	if (ret == -1)
	{
		free(count);
		return (-1);
	}
	a = *count;
	free(count);
	return (a);
}
