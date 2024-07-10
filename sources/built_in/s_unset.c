/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:33:03 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/17 11:41:06 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_str_isalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 'A'|| str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z')
			&& (str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	update_env(t_data *data, int i)
{
	data->nb_var--;
	while (i < data->nb_var - 1)
	{
		data->env[i] = ft_strdup(data->env[i + 1]);
		free(data->env[i + 1]);
		data->env[i + 1] = NULL;
		i++;
	}
}

int	error_unset(t_data *data, int i)
{
	printf("minishell: unset: `%s': not a valid identifier\n", (*data->cmd)->str[i]);
	//ft_putstr_fd("not a valid identifier\n", 2);
	return (data->exit_code = 1);
}

int	mini_pars(t_data *data, int i)
{
	if (ft_isalpha((*data->cmd)->str[i][0]) == 0)
		return (error_unset(data, i));
	if (ft_str_isalnum((*data->cmd)->str[i]) == 1)
		return (error_unset(data, i));
	return (0);
}

int	exe_unset(t_data *data)
{
	int	i;
	int	n;
	//int test;

	n = 1;
	while ((*data->cmd)->str[n] != NULL)
	{
		i = 0;
		if (mini_pars(data, n) == 1)
			return (1);
		while (data->env[i])
		{
			if (ft_strncmp((*data->cmd)->str[n], data->env[i], char_check(0, '=', data->env[i])) == 0)
			{
				free(data->env[i]);
				data->env[i] = NULL;
				if (data->nb_var > i - 1)
					update_env(data, i);
			}
			i++;
		}
		n++;
	}
	i = 0;
	return (0);
}
