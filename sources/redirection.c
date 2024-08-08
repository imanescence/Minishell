/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:41 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/01 11:00:39 by iait-ouf         ###   ########.fr       */
/*   Updated: 2024/07/26 15:08:53 by ssteveli         ###   ########.fr       */
/*   Updated: 2024/07/26 15:43:19 by ssteveli         ###   ########.fr       */
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
	while (temp == NULL || \
			ft_strncmp(temp, cmd->redirection->next->str, \
				ft_strlen(temp)) != 0 || ft_strlen(temp) == 0)
	{
		temp = rl_gets("");
		if (temp == NULL)
			exit (0);
		if (ft_strncmp(temp, cmd->redirection->next->str, \
			ft_strlen(temp)) != 0)
		{
			write(fd, temp, ft_strlen(temp));
			write(fd, "\n", 1);
		}
	}
	close(fd);
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
	(void)data;
	if (cmd->redirection->token == 5)
		redirection_5(cmd);
}
