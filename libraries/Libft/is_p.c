/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:15:58 by ssteveli          #+#    #+#             */
/*   Updated: 2024/01/30 14:43:14 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_p(unsigned long s)
{
	char			*to_print;
	int				leng;

	if (s == 0)
		return (is_str("0x0"));
	leng = len_s(s);
	to_print = ft_calloc(leng + 2, sizeof(char));
	if (!to_print)
		return (0);
	while (s != 0 && leng >= 2)
	{
		if ((s % 16) < 10)
			to_print[leng] = (s % 16) + 48;
		else
			to_print[leng] = (s % 16) + 87;
		s = s / 16;
		leng--;
	}
	to_print[0] = '0';
	to_print[1] = 'x';
	leng = is_str(to_print);
	if (leng == -1)
		return (-1);
	free(to_print);
	return (leng);
}
