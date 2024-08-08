/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:21:22 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/08/01 14:04:02 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_out(t_data *data)
{
	return (data->exit_code = 1);
}

int	mini_pars_out(t_data *data, t_cmd *cmds)
{
	int		i;
	t_list	*list;

	i = 0;
	list = cmds->redirection;
	list = list->next;
	if (list->prev->token == TRUNC)
		data->out_fd = open(list->str, O_WRONLY | O_CREAT
				| O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (list->prev->token == APPEND)
		data->out_fd = open(list->str, O_WRONLY | O_CREAT
				| O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (data->out_fd == -1)
		return (error_out(data));
	return (0);
}

int	outfile_redirection(t_data *data, t_cmd *cmds)
{
	if (mini_pars_out(data, cmds) != 0)
		return (error_out(data));
	if (is_buitin(cmds->str[0]) == 0)
	{
		if (dup2(data->out_fd, STDOUT_FILENO) == -1)
			return (error_out(data));
		close(data->out_fd);
	}
	else
		cmds->builtin(data);
	return (data->exit_code = 0);
}
