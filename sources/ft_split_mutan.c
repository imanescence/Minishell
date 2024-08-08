/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mutan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:50:16 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 13:41:07 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	transchangeins(int i, char **str, int *ins)
{
	*str = transform(*str, i);
	i--;
	*ins = change_in(*ins);
	return (i);
}

char	*dbl_out(char *str, t_data *data)
{
	int	i;
	int	ind;
	int	ins;

	ind = 0;
	ins = 0;
	i = 0;
	while (str[i])
	{
		if (ind == 0 && ins == 0 && str[i] == '-' && \
			ft_strncmp(str, "export", 6) == 0)
			data->exit_code = ft_error_write(str[i]);
		if (str[i] && (str[i] == '\"' || str[i] == '\''))
		{
			if (str[i] == '\"' && ins == 0)
				i = transchangeind(i, &str, &ind);
			else if (str[i] == '\'' && ind == 0)
				i = transchangeins(i, &str, &ins);
		}
		i++;
	}
	return (str);
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
	while (str[i] && j < count)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		size = len_to_sep(str, i, str[i]);
		if (str[i] == '\"' || str[i] == '\'')
			i++;
		if (size != 0)
		{
			ret[j] = ft_calloc(sizeof(char), size + 1);
			ret[j++] = ft_substr(str, i, size);
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

char	**ft_splite_mutan(char *str, t_data *data)
{
	int		count;
	int		j;
	int		size;
	char	**ret;

	(void)data;
	count = num_count2(str);
	if (count == -1)
		return (0);
	if (count == 0)
		return (0);
	ret = ft_calloc(sizeof(char *), count + 1);
	j = 0;
	size = 0;
	return (ft_splite_mutan_bis(str, count, size, ret));
}
