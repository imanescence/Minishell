/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:35 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 15:41:59 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	num_count_bis(int i, char *str)
{
	if (str[i] == ' ' || str[i] == '\t')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	return (i);
}

int	num_count_bisbis(int i, char c, int *count, char *str)
{
	if ((c == '\"' || c == '\'') && str[i] == c)
	{
		if (str[i + 1] == '\0')
			return (error_quot());
		if (str[i + 1] != c)
		{
			(*count)++;
			i++;
			while (str[i] && str[i] != c)
				i++;
			if (str[i] == '\0')
				return (error_quot());
			i++;
		}
		else
			i += 2;
	}
	return (i);
}

int	num_count(char *s, char c)
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

int	num_count2(char *str)
{
	int		i;
	int		*count;
	char	c;
	int		res;

	i = 0;
	count = ft_calloc(1, sizeof(int));
	*count = 0;
	while (str[i])
	{
		c = str[i];
		i = num_count_bisbis(i, c, count, str);
		if (str[i] && (str[i] != ' ' && str[i] != '\t'))
		{
			(*count)++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t') \
					&& str[i] != '\'' && str[i] != '\"')
				i++;
		}
		i = num_count_bis(i, str);
	}
	res = *count;
	free(count);
	return (res);
}
