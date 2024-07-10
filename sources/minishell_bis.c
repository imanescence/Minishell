/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:36:35 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/05 17:39:17 by ssteveli         ###   ########.fr       */
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
	}
}

void	init_minishell(t_data **d, t_cmd ***c, t_list ***l, char **e)
{
	(*l) = ft_calloc(1, sizeof(t_list));
	(*c) = ft_calloc(1, sizeof(t_cmd));
	(*d) = ft_calloc(1, sizeof(t_data));
	(*d) = init_env((*d), e, (*c));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, &sign_handler);
}

int	launch_mini(char **str, t_data *data, t_cmd **cmd, t_list **lexer )
{
	char	*str_temp;

	str_temp = rl_gets("minishell :  ");
	str_temp = hextend(str_temp, data);
	ft_printf("str temp = %s\n", str_temp);
	if (str_temp != 0)
	{
		str = ft_splite_mutan(str_temp);
		if (str != 0)
		{
			
			get_lexer(lexer, str);
			if (get_cmds(lexer, cmd) == 1)
				return (free_all(lexer, cmd, str));
			if ((*cmd)->redirection && (*cmd)->redirection->token == 6)
			{
				ft_printf("error redirection cant open file");
				return (0);
			}
			(*cmd)->fd_herdoc = -1;
			print_cmd(cmd, data);
			execut(cmd, data);
		}
		return (1);
	}
	else
		return (0);
}
