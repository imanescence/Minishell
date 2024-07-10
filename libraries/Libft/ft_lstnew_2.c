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

t_cmd	*new_2(int (*bn)(struct s_data *), t_list *red, char **s, t_cmd *pv)
{
	t_cmd	*list;

	list = malloc(sizeof(t_cmd));
	if (!list)
		return (0);
	list->str = s;
	list->builtin = bn;
	list->redirection = red;
	list->prev = pv;
	list->next = 0;
	return (list);
}
