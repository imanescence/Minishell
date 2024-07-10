/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:26:03 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:42:59 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenint(const int *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str = str + 1;
	}
	return (count);
}
