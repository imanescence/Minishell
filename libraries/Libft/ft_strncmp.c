/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:09:11 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/13 17:47:10 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_test_str(const unsigned char *s1, const unsigned char *s2, int i)
{
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	else if (s1[i] != '\0')
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (((unsigned char *)(s2))[i] != '\0'
		&& ((unsigned char *)s1)[i] != '\0' && i < n)
	{
		if (((unsigned char *)s2)[i] < ((unsigned char *)s1)[i])
			return (1);
		else if (((unsigned char *)s2)[i] > ((unsigned char *)s1)[i])
			return (-1);
		else
			i++;
	}
	if (i >= n)
		return (0);
	return (ft_test_str((unsigned char *)s1, (unsigned char *)s2, i));
}
