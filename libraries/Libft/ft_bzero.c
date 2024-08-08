/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:28:58 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/20 17:03:10 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *a, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = a;
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
