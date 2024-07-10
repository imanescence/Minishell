/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:24:10 by ssteveli          #+#    #+#             */
/*   Updated: 2024/02/14 12:24:10 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *stack)
{
	int		i;
	t_list	*temp;

	temp = stack;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
