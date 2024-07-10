/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:47:07 by ssteveli          #+#    #+#             */
/*   Updated: 2024/04/24 16:47:07 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"	

void	sup_list2(t_list *temp_lexer)
{
	if (temp_lexer->prev)
	{
		if (temp_lexer->next != 0)
		{
			temp_lexer->prev->next = temp_lexer->next;
			temp_lexer->next->prev = temp_lexer->prev;
		}
		else
			temp_lexer->prev->next = 0;
	}
}

t_list	*get_lexer_bis(t_list **lexer, char **a, t_list *prev, int i)
{
	if (ft_strncmp(a[i], ">>", 2) == 0)
	{
		prev = ft_lstnew(APPEND, 0, i, prev);
		ft_lstadd_back(lexer, prev);
	}
	else if (ft_strncmp(a[i], "<<", 2) == 0)
	{
		prev = ft_lstnew(HEREDOC, 0, i, prev);
		ft_lstadd_back(lexer, prev);
	}
	else
	{
		prev = ft_lstnew(Not_a_token, a[i], i, prev);
		ft_lstadd_back(lexer, prev);
	}
	return (prev);
}

t_list	**lexer_condi(t_list **lexer)
{
	if ((*lexer))
	{
		while (*lexer)
		{
			free(*lexer);
			(*lexer) = (*lexer)->next;
		}
	}
	return (lexer);
}

void	get_lexer(t_list **lexer, char **a)
{
	int		i;
	t_list	*prev;

	lexer = lexer_condi(lexer);
	i = -1;
	while (a[++i])
	{
		if (ft_strncmp(a[i], "|", 1) == 0)
		{
			prev = ft_lstnew(Pipe, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else if (ft_strncmp(a[i], "<", 2) == 0)
		{
			prev = ft_lstnew(INPUT, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else if (ft_strncmp(a[i], ">", 2) == 0)
		{
			prev = ft_lstnew(TRUNC, 0, i, prev);
			ft_lstadd_back(lexer, prev);
		}
		else
			prev = get_lexer_bis(lexer, a, prev, i);
	}
}
