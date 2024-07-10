/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:31:54 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/15 10:49:15 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exe_echo(t_data *data)
{
	int	i;

	i = 1;
	while ((*data->cmd)->str[i] != NULL)
	{
		if (ft_strncmp((*data->cmd)->str[1], "-n", 2) != 0)
		{
			if (i != 0)
				printf(" ");
			printf("%s", (*data->cmd)->str[i]);
		}
		i++;
	}
	if (ft_strncmp((*data->cmd)->str[1], "-n", 2) == 0)
		return (0);
	else
		printf("\n");
	return (0);
}
