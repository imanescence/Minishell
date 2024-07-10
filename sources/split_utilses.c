/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utilses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:45:45 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/26 14:03:09 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_quot(void)
{
	ft_printf("error quot\n");
	return (-1);
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
		while (str[i] && str[i] != c)
		{
			count++;
			i++;
		}
		return (count);
	}
	else if (str[i] != ' ')
	{
		while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"')
		{
			count++;
			i++;
		}
		return (count);
	}
	return (0);
}
