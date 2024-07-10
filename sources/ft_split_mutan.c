/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mutan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:16 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/26 14:04:56 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_splite_mutan_bisbis(int i, int size, char *str)
{
	char	c;

	c = str[i - 1];
	i += size;
	if (size != 0 && (c == '\'' || c == '\"'))
	{
		while (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
		i++;
		while (str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
	}
	return (i);
}

int	ft_bis_split_mutan(int i, char *str)
{
	if (str[i] == '\'')
	{
		while (str[i] == '\'')
			i++;
	}
	else if (str[i] == '\"')
	{
		while (str[i] == '\"')
			i++;
	}
	return (i);
}

char	**ft_splite_mutan_bis(char *str, int count, int size, char **ret)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j <= count)
	{
		size = 0;
		while (str[i] == ' ')
			i++;
		size = len_to_sep(str, i, str[i]);
		if (size != 0)
		{
			ret[j] = ft_calloc(sizeof(char), size + 1);
			ret[j] = ft_substr(str, i = ft_bis_split_mutan(i, str), size);
			j++;
		}
		else
		{
			i += 2;
			count++;
		}
		i = ft_splite_mutan_bisbis(i, size, str);
	}
	return (ret);
}

char	**ft_splite_mutan(char *str)
{
	int		count;
	int		j;
	int		size;
	char	**ret;

	count = num_count(str);
	if (count == -1)
		return (0);
	if (count == 0)
		return (0);
	ret = ft_calloc(sizeof(char *), count + 1);
	j = 0;
	size = 0;
	return (ft_splite_mutan_bis(str, count, size, ret));
}
