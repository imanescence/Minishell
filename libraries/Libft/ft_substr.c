/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:40:28 by ssteveli          #+#    #+#             */
/*   Updated: 2024/03/06 15:39:51 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sub_ft_substr(char const *s, unsigned int start, size_t len,
		char *new)
{
	int		i;
	size_t	j;

	i = start;
	j = 0;
	while (j < len && s[i])
		new[j++] = s[i++];
	new[j++] = 0;
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (0);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if ((unsigned int)ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (0);
	return (sub_ft_substr(s, start, len, new));
}
