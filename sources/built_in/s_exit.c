/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:25 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/26 11:24:04 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	c_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	error_exit(t_data *data, const char *str, int flag)
{
	(void) str;
	if (flag == 0)
	{
		write(2, "minishell: exit: ", 17);
		write(2, (*data->cmd)->str[1], ft_strlen((*data->cmd)->str[1]));
		write(2, " numeric argument required\n", 27);
		exit(data->exit_code = 255);
	}
	if (flag == 1)
	{
		write(2, "minishell: exit: ", 17);
		write(2, (*data->cmd)->str[2], ft_strlen((*data->cmd)->str[2]));
		write(2, " numeric argument required\n", 28);
		return (data->exit_code = 1);
	}
	return (0);
}

long	ft_atol(t_data *data, const char *str)
{
	int			i;
	long long	nb;
	long		ng;

	i = 0;
	nb = 0;
	ng = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ng *= -1;
		i++;
	}
	if (!c_isdigit(str[i]))
		return (error_exit(data, str, 0));
	while (c_isdigit(str[i]))
	{
		nb = nb * 10;
		nb = nb + (str[i++] - '0');
	}
	if ((nb * ng) > LONG_MAX || (nb * ng) < LONG_MIN)
		return (error_exit(data, str, 0));
	return (data->exit_code = (long)(nb * ng));
}

int	no_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (1);
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (0);
}

int	exe_exit(t_data *data)
{
	int	i;

	i = 1;
	if (ft_strncmp((*data->cmd)->str[0], "exit", 4) == 1
		&& (*data->cmd)->str[2] && (*data->cmd)->str[2]
		&& no_digit((*data->cmd)->str[2]) == 1)
	{
		write(2, "minishell: exit: ", 15);
		write(2, (*data->cmd)->str[2], ft_strlen((*data->cmd)->str[2]));
		write(2, " numeric argument required\n", 29);
	}
	if ((*data->cmd)->str[i])
		data->exit_code = ft_atol(data, (*data->cmd)->str[i]);
	if (count_str(data) > 2)
		return (error_exit(data, "exit", 1));
	printf("exit\n");
	exit (data->exit_code);
}
