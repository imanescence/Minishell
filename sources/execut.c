/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:31:42 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/21 15:42:03 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	is_not_builtin(t_data *data)
{
	find_cmd(data);
}

void	execut_simple(t_cmd *cmd, t_data *data)
{
	if (cmd->redirection != 0)
		redirect(cmd, data);
	if (is_buitin(cmd->str[0]) == 1)
	{
		cmd->builtin(data);
	}
	else
		is_not_builtin(data);
}

void	execut_pipe(t_data *data)
{
	ft_printf("it's a pipe\n");
	pipe_redirection(data);
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
		execut_pipe(data);
	}
}
