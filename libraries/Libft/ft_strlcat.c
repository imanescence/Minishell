/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:53:18 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/23 13:26:16 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (ft_strlen(src));
	if (len_src == 0)
		return (len_dest);
	i = len_dest;
	j = 0;
	while (src[j] != '\0' && i < (size - 1))
		dest[i++] = src[j++];
	dest[i] = 0;
	if (size > len_dest)
		return (len_src + len_dest);
	return (len_src + size);
}
