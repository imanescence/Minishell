/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:57:09 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/07/26 09:57:49 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	swap_pipes(int src[2], int dest[2])
{
	dest[0] = src[0];
	dest[1] = src[1];
}

void	waiting_children(void)
{
	while (wait(NULL) != -1)
	{
		continue ;
	}
}

int	link_lists_counter(t_data *data)
{
	int		i;
	t_cmd	*cmds;

	i = 0;
	cmds = (*data->cmd);
	while (cmds != NULL)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}
