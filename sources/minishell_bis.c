/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:36:35 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 15:50:44 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sign_handler(int code)
{
	if (code == SIGINT)
	{
		if (g_glob.in_heredoc != 1)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		else
			write(1, "\n", 1);
	}
}

void	init_minishell(t_data **d, t_cmd ***c, char **e)
{
	(*c) = ft_calloc(1, sizeof(t_cmd));
	(*d) = ft_calloc(1, sizeof(t_data));
	(*d) = init_env((*d), e, (*c));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, &sign_handler);
}

int	error_file(void)
{
	ft_printf("No such file or directory\n");
	return (0);
}

int	launch_mini(char **str, t_data *data, t_cmd **cmd, t_list **lexer )
{
	char	*str_temp;

	str_temp = rl_gets("minishell :  ");
	str_temp = hextend(str_temp, data);
	if (str_temp != 0)
	{
		if (ft_strncmp(str_temp, "minishell", 9) == 0 || \
			ft_strncmp(str_temp, "./minishell", 11) == 0)
			shlvl_updater(data);
		str = ft_splite_mutan(str_temp, data);
		if (str != 0)
		{
			get_lexer(lexer, str);
			if (get_cmds(lexer, cmd) == 1)
				return (free_all(lexer, cmd, str));
			if ((*cmd)->redirection && (*cmd)->redirection->token == 6)
				error_file();
			else
				execut(cmd, data);
			(*cmd)->fd_herdoc = -1;
		}
		return (1);
	}
	return (0);
}
