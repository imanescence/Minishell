/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expender_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:38:25 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 15:41:45 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	len_to_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char	*after_egal(char *str)
{
	int		i;
	char	*a;
	int		j;

	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	a = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	j = 0;
	while (str[i])
	{
		a[j] = str[i];
		j++;
		i++;
	}
	return (a);
}

int	len_to_space(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && (str[i] != ' ' && str[i] != '\t') && \
			!(i > 0 && str[i] == '?' && \
				str[i - 1] == '$'))
	{
		len++;
		i++;
	}
	return (len);
}

char	*load_str(char *a, int i)
{
	int		len;
	char	*str;
	int		j;

	len = len_to_space(a, i);
	str = ft_calloc(len + 1, sizeof(char));
	i++;
	j = 0;
	while (a[i] && (a[i] != ' ' && a[i] != '\t') \
			&& a[i] != '\"' && a[i] != '\'')
	{
		str[j] = a[i];
		if (a[i] == '?')
			return (str);
		i++;
		j++;
	}
	str[j] = '=';
	return (str);
}
