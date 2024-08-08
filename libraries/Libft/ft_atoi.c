/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:22:55 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 15:20:43 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_len_num(const char *str, int i)
{
	int	k;
	int	size;

	size = 0;
	k = i;
	while (str[k] > 47 && str[k] < 58)
	{
		size++;
		k++;
	}
	return (size);
}

int	ft_print_int_atoi(const char *str, int i, char sign)
{
	long long int	number;
	long long int	test;

	number = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		test = number;
		number = (number * 10) + (str[i] - 48);
		i++;
		if (test > number)
		{
			if (sign == 'a')
				return (0);
			else
				return (-1);
		}
	}
	if (sign == 'a')
		number = number * -1;
	return (number);
}

int	ft_atoi(const char *str)
{
	int		i;
	char	sign;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = 'a';
	else
		sign = 'b';
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (ft_print_int_atoi(str, i, sign));
	else
		return (0);
}
