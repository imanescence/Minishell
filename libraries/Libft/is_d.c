/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:40:28 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:43:12 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(int n)
{
	int	i;
	int	leng;

	i = n;
	leng = 0;
	if (n == 0)
		return (1);
	while (i >= 1)
	{
		i /= 10;
		leng++;
	}
	while (i <= -1)
	{
		i /= 10;
		leng++;
	}
	if (n < 0)
		leng++;
	return (leng);
}

static int	ft_putnb_rec(int nb)
{
	unsigned int	b;
	int				ret;

	b = nb;
	while (nb > 9)
	{
		b = nb % 10;
		nb = ft_putnb_rec(nb / 10);
		if (nb == -1)
			return (-1);
	}
	b = '0' + b;
	ret = write(1, &b, 1);
	if (ret == -1)
		return (-1);
	return (nb);
}

int	is_d(int nb)
{
	char			a;
	unsigned int	un_nb;
	int				ret;

	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	a = '-';
	if (nb < 0)
	{
		ret = write(1, &a, 1);
		un_nb = nb * -1;
		if (ret == -1)
			return (-1);
	}
	else
	{
		un_nb = nb;
	}
	ret = ft_putnb_rec(un_nb);
	if (ret == -1)
		return (-1);
	return (len_int(nb));
}
