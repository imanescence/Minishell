/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:44:47 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/08 16:07:25 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	**bubble_sort(t_data *data)
{
	int		i;
	int		j;
	char	**ar_sorted;

	ar_sorted = ar_dup_or_raised(data, data->env, NULL);
	i = 0;
	while (i < data->nb_var - 2)
	{
		j = 0;
		while (j < (data->nb_var - i) - 1)
		{
			if (j == data->nb_var -2)
				break ;
			if (ft_strncmp(ar_sorted[j], ar_sorted[j + 1],
					ft_strlen(ar_sorted[j])) > 0)
			{
				ft_swap(&ar_sorted[j], &ar_sorted[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (ar_sorted);
}

void	free_char_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar != NULL && ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
}

void	display_writer(char **strs, int i, int j, t_data *data)
{
	while (strs[i][j])
	{
		if (j && strs[i][j - 1] == '=')
			break ;
		write(data->out_fd, &strs[i][j], 1);
		j++;
	}
	write(data->out_fd, "\"", 1);
	while (strs[i][j])
	{
		write(data->out_fd, &strs[i][j], 1);
		j++;
	}
}

void	export_display(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->env_tmp = bubble_sort(data);
	while (data->env_tmp != NULL && data->env_tmp[i])
	{
		j = 0;
		write(data->out_fd, "declare -x ", 11);
		if (char_check(0, '=', data->env_tmp[i]) == -1)
		{
			ft_putstr_fd(data->env_tmp[i], data->out_fd);
			write(data->out_fd, "\n", 1);
			i++;
		}
		else if (char_check(0, '=', data->env_tmp[i]) != -1)
		{
			display_writer(data->env_tmp, i, j, data);
			write(data->out_fd, "\"\n", 2);
			i++;
		}
	}
	free_char_ar(data->env_tmp);
}
