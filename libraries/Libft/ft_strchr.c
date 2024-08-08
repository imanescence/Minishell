/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:45:49 by ssteveli          #+#    #+#             */
/*   Updated: 2024/03/27 13:45:49 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *a, int c, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (a[i] == c)
			return (1);
		i++;
	}
	return (0);
}
