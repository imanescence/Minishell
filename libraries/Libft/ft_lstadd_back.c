/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:52:57 by ssteveli          #+#    #+#             */
/*   Updated: 2023/10/24 11:51:54 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *news)
{
	t_list	*temp;

	if (!lst || !news)
		return ;
	if (*lst == 0)
	{
		*lst = news;
		return ;
	}
	temp = *lst;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = news;
}
