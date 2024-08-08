/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utilses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:45:45 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 15:43:02 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_quot(void)
{
	ft_printf("error quot\n");
	return (-1);
}

int	is_dif(char c, char *str, int i)
{
	if (str[i] == c)
	{
		if (str[i] != c && str[i + 1] != c)
			return (1);
	}
	return (0);
}

int	len_to_sep(char *str, int i, char c)
{
	int	count;

	count = 0;
	if (c == '\'' || c == '\"')
	{
		if (str[i] && str[i + 1] == c)
			return (0);
		i++;
		while (str[i++] && str[i] != c)
			count++;
		return (count + 1);
	}
	else if (str[i] != ' ' && str[i] != '\t')
	{
		while (str[i] && (str[i] != ' ' && str[i] != '\t') \
				&& is_dif('\'', str, i) == 0 \
					&& is_dif('\"', str, i) == 0)
		{
			count++;
			i++;
		}
		return (count);
	}
	return (0);
}
