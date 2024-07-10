/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:16 by ssteveli          #+#    #+#             */
/*   Updated: 2024/03/06 15:33:26 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	test_ft_free(char **s, int j)
{
	if (!s[j])
	{
		while (j-- > 0)
			free(s[j]);
		free(s);
		return (0);
	}
	return (1);
}

int	ft_num_word(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

int	ft_len_to_sep(const char *s, char c, int i)
{
	int	len_to_sepa;

	len_to_sepa = 0;
	while (s[i] != c && s[i])
	{
		len_to_sepa++;
		i++;
	}
	return (len_to_sepa);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;
	int		size;
	int		num_word;

	i = 0;
	j = -1;
	num_word = ft_num_word(s, c);
	new = (char **)malloc(sizeof(char *) * (num_word + 1));
	if (!new)
		return (0);
	while (++j < num_word)
	{
		while (s[i] == c)
			i++;
		size = ft_len_to_sep(s, c, i);
		new[j] = ft_substr(s, i, size);
		if (test_ft_free(new, j) == 0)
			return (0);
		i += size;
	}
	new[j] = 0;
	return (new);
}
