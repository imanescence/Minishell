/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:01:10 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/25 16:04:41 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_error_write(char str)
{
	write(2, "minishell: cd: ", 15);
	write(2, &(str), 1);
	write(2, " not a valid identifier\n", 24);
	return (1);
}

int	ft_splite_mutan_bisbis(int i, int size, char *str)
{
	char	c;

	if (str && str[i] == 0)
		return (i);
	if (i != 0)
		c = str[i - 1];
	i += size;
	if (size != 0 && (c == '\'' || c == '\"'))
	{
		while (str && str[i] && str[i] != '\'' && str[i] != '\"')
			i++;
		if (str[i] != 0)
			i++;
		while (str && str[i] != 0 && str[i] != '\'' && str[i] != '\"')
		{
			i++;
		}
	}
	return (i);
}

char	*transform(char *str, int i)
{
	str = ft_strnjoin(ft_substr(str, 0, i), \
			ft_substr(str, i + 1, ft_strlen(str)));
	return (str);
}

int	change_in(int in)
{
	if (in == 1)
		in = 0;
	else
		in = 1;
	return (in);
}

int	transchangeind(int i, char **str, int *ind)
{
	*str = transform(*str, i);
	i--;
	*ind = change_in(*ind);
	return (i);
}
