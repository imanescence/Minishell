/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 09:24:38 by ggane             #+#    #+#             */
/*   Updated: 2024/07/15 17:48:20 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*to_sup;
	t_list	*prochain_maillon;

	to_sup = *alst;
	while (to_sup)
	{
		prochain_maillon = to_sup->next;
		free(to_sup);
		to_sup = prochain_maillon;
	}
}
