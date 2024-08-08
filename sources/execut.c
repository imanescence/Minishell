/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:31:42 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/01 13:32:26 by iait-ouf         ###   ########.fr       */
/*   Updated: 2024/07/26 14:40:45 by ssteveli         ###   ########.fr       */
/*   Updated: 2024/07/26 15:37:45 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	is_not_builtin(t_data *data)
{
	one_command(data);
}

void	execut_simple(t_cmd *cmd, t_data *data)
{
	if (cmd->redirection != 0)
		redirect(cmd, data);
	if (is_buitin(cmd->str[0]) == 1)
	{
		if (cmd->redirection)
			redirection_check(data, cmd);
		else
			cmd->builtin(data);
	}
	else
		is_not_builtin(data);
}

void	execut(t_cmd **cmd, t_data *data)
{
	t_cmd	*temp_cmd;

	temp_cmd = *cmd;
	if (temp_cmd->next == 0)
	{
		execut_simple(temp_cmd, data);
	}
	else
	{
		multi_pipe(data);
	}
}
