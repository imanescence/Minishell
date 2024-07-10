/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_return.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:27:34 by ssteveli          #+#    #+#             */
/*   Updated: 2024/05/15 14:42:33 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	error_return(int i, char *str)
{
	if (i == 1)
	{
		ft_printf("%s: command not found\n", str);
		exit(127);
	}
}
