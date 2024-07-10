/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:31:01 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/20 17:14:48 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	char		*cpy;
	size_t		i;

	i = 0;
	len = ft_strlen(s);
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (0);
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
