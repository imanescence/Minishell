/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:26:29 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/24 13:39:54 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_token token, char *str, int i, t_list *prev)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		return (0);
	list->i = i;
	list->next = 0;
	list->str = str;
	list->token = token;
	list->prev = prev;
	return (list);
}
