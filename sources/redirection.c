/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:41 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/24 14:04:15 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	redirection_5_bis(char *temp, t_cmd *cmd)
{
	int	fd;

	signal(SIGINT, SIG_DFL);
	fd = open("herdoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == 0)
		exit(0);
	while (temp == 0 || \
			ft_strncmp(temp, cmd->redirection->next->str, \
				ft_strlen(cmd->redirection->next->str)) != 0)
	{
		temp = rl_gets("");
		if (ft_strncmp(temp, cmd->redirection->next->str, \
			ft_strlen(temp)) != 0)
			write(fd, temp, ft_strlen(temp));
	}
	close(fd);
	fd = open("herdoc.txt", O_RDONLY);
	cmd->fd_herdoc = fd;
}

int	redirection_5(t_cmd *cmd)
{
	char	*temp;
	int		pid;

	pid = fork();
	temp = 0;
	g_glob.in_heredoc = 1;
	if (pid == 0)
	{
		redirection_5_bis(temp, cmd);
		exit(0);
	}
	else
		waitpid(pid, 0, 0);
	g_glob.in_heredoc = 0;
	return (0);
}

void	redirect(t_cmd *cmd, t_data *data)
{
	ft_printf("redirection %d detected\n", cmd->redirection->token);
	if (cmd->redirection->token == 2)
		redirection_2(data);
	if (cmd->redirection->token == 3)
		redirection_3(cmd, data);
	if (cmd->redirection->token == 4)
		redirection_4(data);
	if (cmd->redirection->token == 5)
		redirection_5(cmd);
}
