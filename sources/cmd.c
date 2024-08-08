/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:34:27 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/06 15:49:09 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"	

int	(*ch_bn(t_list **ad_lexer))(struct s_data *struc)
{
	t_list	*lexer;

	lexer = *ad_lexer;
	while (lexer && lexer->token != Pipe)
	{
		if (ft_strncmp(lexer->str, "cd", 3) == 0)
			return (&(exe_cd));
		else if (ft_strncmp(lexer->str, "echo", 5) == 0)
			return (&(exe_echo));
		else if (ft_strncmp(lexer->str, "env", 4) == 0)
			return (&(exe_env));
		else if (ft_strncmp(lexer->str, "exit", 5) == 0)
			return (&(exe_exit));
		else if (ft_strncmp(lexer->str, "export", 7) == 0)
			return (&(exe_export));
		else if (ft_strncmp(lexer->str, "pwd", 4) == 0)
			return (&(exe_pwd));
		else if (ft_strncmp(lexer->str, "unset", 6) == 0)
			return (&(exe_unset));
		else
			return (0);
	}
	return (0);
}

int	is_token_bisbis(t_list	**tp, t_list **pv, t_list **ll, int l)
{
	if ((*ll)->token != 0 && (*ll)->next == 0)
	{
		ft_printf("redirection error\n");
		exit(0);
	}
	if ((*pv) == 0)
	{
		(*pv) = ft_lstnew((*ll)->token, 0, 0, 0);
		(*tp) = (*pv);
		l = 1;
	}
	else if ((*ll)->token == 0)
	{
		(*pv) = ft_lstnew(0, (*ll)->str, 0, (*pv));
		ft_lstadd_back(tp, (*pv));
	}
	else
	{
		(*pv) = ft_lstnew((*ll)->token, 0, 0, (*pv));
		ft_lstadd_back(tp, (*pv));
	}
	return (0);
}

t_list	*is_token_bis(t_list	*tp, t_list *pv, t_list *ll)
{
	int	k;
	int	l;

	l = 0;
	while (ll && ll->token != Pipe)
	{
		if (ll->token == 4)
		{
			k = open(ll->next->str, O_RDONLY);
			if (k == -1)
			{
				ll->token = error_6(ll->next->str);
			}
			else
				close (k);
		}
		if (ll->token != Not_a_token || l == 1)
		{
			l = 1;
			is_token_bisbis(&tp, &pv, &ll, l);
		}
		ll = ll->next;
	}
	return (tp);
}

t_cmd	*get_cmds_bis(t_list *tl, t_cmd *tc, t_cmd *prev, t_list **lx)
{
	int	i;

	i = 0;
	while (tl)
	{
		if (prev == 0)
		{
			tc = new_2(ch_bn(lx), is_t(lx), is_s(lx), 0);
			prev = tc;
		}
		else
		{
			prev = new_2(ch_bn(lx), is_t(lx), is_s(lx), prev);
			ft_lstadd_back2(&tc, prev);
		}
		if (prev->str == 0)
			return (0);
		while (tl && tl->token != Pipe)
			tl = tl->next;
		if (tl && tl->token == Pipe)
			tl = tl->next;
		i++;
		lx = &(tl);
	}
	return (tc);
}

int	get_cmds(t_list **lexer, t_cmd **cmds)
{
	t_list	*temp_lexer;
	t_cmd	*temp_cmds;
	t_cmd	*prev;
	t_list	**add_lexer;

	add_lexer = lexer;
	temp_lexer = *lexer;
	temp_cmds = *cmds;
	prev = 0;
	temp_cmds = get_cmds_bis(temp_lexer, temp_cmds, prev, lexer);
	if (temp_cmds == 0)
		return (1);
	*cmds = temp_cmds;
	lexer = add_lexer;
	return (0);
}
