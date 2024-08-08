/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:37 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 13:11:24 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	var_adder(t_data *data)
{
	int	i;

	i = 0;
	data->env_tmp = ar_dup_or_raised(data, data->env, (*data->cmd)->str);
	free_char_ar(data->env);
	data->env = ar_dup_or_raised(data, data->env_tmp, NULL);
	free_char_ar(data->env_tmp);
}

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			return (1);
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (0);
}

int	exe_export(t_data *data)
{
	int	i;

	i = -1;
	printf("cecie est ma str %s|\n", (*data->cmd)->str[1]);
	if ((*data->cmd)->str[1] && (ft_strncmp((*data->cmd)->str[1], "=", 2) == 0
			|| ft_digit((*data->cmd)->str[1]) == 1))
	{
		write(2, "minishell: export: ", 19);
		write(2, (*data->cmd)->str[1],
			ft_strlen((*data->cmd)->str[1]));
		write(2, " not a valid identifier\n", 24);
		data->exit_code = 1;
	}
	data->nb_input = count_str(data) - 1;
	if (data->nb_input > 0)
		var_adder(data);
	else
		export_display(data);
	return (0);
}
