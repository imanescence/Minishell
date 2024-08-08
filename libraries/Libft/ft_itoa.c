/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:46:30 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/26 14:30:48 by ssteveli         ###   ########.fr       */
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

static int	sub_itoa(int n, char *new, int leng, int i)
{
	if (n < 0)
	{
		n *= -1;
		new[0] = '-';
	}
	while (n >= 1)
	{
		new[leng - ++i] = '0' + n % 10;
		n /= 10;
	}
	return (leng);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		i;
	int		leng;

	if (n == -2147483648)
	{
		new = ft_strdup("-2147483648");
		return (new);
	}
	leng = len_int(n);
	i = 0;
	new = (char *)malloc(sizeof(char) * (leng + 1));
	if (!new)
		return (0);
	if (n == 0)
		new[0] = '0';
	leng = sub_itoa(n, new, leng, i);
	new[leng] = 0;
	return (new);
}
