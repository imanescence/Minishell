/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:15:58 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:43:20 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_x(unsigned int s)
{
	char			*to_print;
	int				leng;

	if (s == 0)
		return (is_chr('0'));
	leng = len_s(s) - 2;
	to_print = ft_calloc(leng + 2, sizeof(char));
	if (!to_print)
		return (-1);
	while (s != 0 && leng >= 0)
	{
		if ((s % 16) < 10)
			to_print[leng] = (s % 16) + 48;
		else
			to_print[leng] = (s % 16) + 87;
		s = s / 16;
		leng--;
	}
	leng = is_str(to_print);
	free(to_print);
	if (leng == -1)
		return (-1);
	return (leng);
}
