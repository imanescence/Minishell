/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:31:54 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/01 18:09:14 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exe_echo(t_data *data)
{
	int	i;

	i = 1;
	while ((*data->cmd)->str[i] != NULL)
	{
		if (i != 1)
			write(data->out_fd, " ", 1);
		if (ft_strncmp((*data->cmd)->str[1], "-n", 2) == 0)
			i++;
		ft_putstr_fd((*data->cmd)->str[i], data->out_fd);
		i++;
	}
	if (ft_strncmp((*data->cmd)->str[1], "-n", 2) == 0)
		return (0);
	else
		write(data->out_fd, "\n", 1);
	return (0);
}
