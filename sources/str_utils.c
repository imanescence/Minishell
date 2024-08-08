/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 09:25:47 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/07/26 11:17:39 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strnjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	if (i == 0 && j == 0)
		return (NULL);
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (++i != -1 && s1 && s1[i])
		str[i] = s1[i];
	while (++j != -1 && s2 && s2[j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

int	char_check(char cmp, char to_find, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (cmp == to_find)
			return (0);
	}
	else
	{
		while (str[i])
		{
			if (str[i] == to_find)
				return (i);
			i++;
		}
	}
	return (-1);
}

char	**ar_dup(t_data *data, char **tab)
{
	int		i;
	char	**new_ar;

	i = 0;
	new_ar = (char **) malloc ((data->nb_input + 1) * sizeof(char *));
	if (!new_ar)
		exit(1);
	while (tab[i] && i < data->nb_input)
	{
		new_ar[i] = ft_strdup(tab[i]);
		i++;
	}
	new_ar[i] = NULL;
	return (new_ar);
}

int	count_str(t_data *data)
{
	int	i;

	i = 0;
	while ((*data->cmd)->str != NULL && (*data->cmd)->str[i])
		i++;
	return (i);
}
