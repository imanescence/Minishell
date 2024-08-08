/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_multi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:53:39 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/07/26 15:45:32 by iait-ouf         ###   ########.fr       */
/*   Updated: 2024/07/19 15:15:21 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	first_command(t_data *data, t_cmd *cmds)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		g_glob.in_heredoc = 1;
		close(data->pipe_in[READ]);
		close(data->pipe_in[WRITE]);
		close(data->pipe_out[READ]);
		dup2(data->pipe_out[WRITE], STDOUT_FILENO);
		close(data->pipe_out[WRITE]);
		if (cmds->redirection)
			redirection_check(data, cmds);
		find_cmd(data, cmds);
	}
	return (0);
}

int	last_command(t_data *data, t_cmd *cmds)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		g_glob.in_heredoc = 1;
		close(data->pipe_out[READ]);
		close(data->pipe_out[WRITE]);
		close(data->pipe_in[WRITE]);
		dup2(data->pipe_in[READ], STDIN_FILENO);
		close(data->pipe_in[READ]);
		if (cmds->redirection)
			redirection_check(data, cmds);
		find_cmd(data, cmds);
	}
	return (0);
}

int	middle_command(t_data *data, t_cmd *cmds)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		g_glob.in_heredoc = 1;
		close(data->pipe_in[WRITE]);
		dup2(data->pipe_in[READ], STDIN_FILENO);
		close(data->pipe_in[READ]);
		close(data->pipe_out[READ]);
		dup2(data->pipe_out[WRITE], STDOUT_FILENO);
		close(data->pipe_out[WRITE]);
		if (cmds->redirection)
			redirection_check(data, cmds);
		find_cmd(data, cmds);
	}
	return (0);
}

int	multi_pipe(t_data *data)
{
	t_cmd	*cmds;
	int		i;
	int		nb_cmds;

	i = 0;
	cmds = (*data->cmd);
	nb_cmds = link_lists_counter(data);
	pipe(data->pipe_in);
	while (i < nb_cmds)
	{
		pipe(data->pipe_out);
		if (i == 0)
			first_command(data, cmds);
		else if (i == nb_cmds - 1)
			last_command(data, cmds);
		else
			middle_command(data, cmds);
		close(data->pipe_in[READ]);
		close(data->pipe_in[WRITE]);
		swap_pipes(data->pipe_out, data->pipe_in);
		cmds = cmds->next;
		i++;
	}
	waiting_children();
	return (0);
}
