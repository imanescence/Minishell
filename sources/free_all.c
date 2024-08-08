/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:44:18 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/15 17:46:48 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_lstdel_cmd(t_cmd **cmd)
{
	t_cmd	*a_effacer;
	t_cmd	*prochain_maillon;
	int		i;

	i = -1;
	a_effacer = *cmd;
	while (a_effacer)
	{
		prochain_maillon = a_effacer->next;
		free(a_effacer->str);
		ft_lstdel(&(a_effacer->redirection));
		free(a_effacer);
		a_effacer = prochain_maillon;
	}
	*cmd = NULL;
}

int	free_all(t_list **lexer, t_cmd **cmd, char **str)
{
	int	i;

	if (*cmd && (*cmd)->fd_herdoc != -1)
		close((*cmd)->fd_herdoc);
	if (lexer != 0)
	{
		ft_lstdel(lexer);
		free(lexer);
		lexer = 0;
	}
	if (cmd != 0)
	{
		ft_lstdel_cmd(cmd);
		free(cmd);
	}
	i = -1;
	if (str != 0)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
	return (1);
}
