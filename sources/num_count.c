/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:44:35 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/05 16:17:43 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	num_count_bis(int i, char *str)
{
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
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

int	num_count(char *str)
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
		if (str[i] && str[i] != ' ')
		{
			(*count)++;
			while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
				i++;
		}
		i = num_count_bis(i, str);
	}
	res = *count;
	free(count);
	return (res);
}
