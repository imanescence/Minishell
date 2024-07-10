/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:34:59 by ssteveli          #+#    #+#             */
/*   Updated: 2024/05/07 18:34:59 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_buitin(char *a)
{
	if (a == 0)
		return (0);
	if (ft_strncmp(a, "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(a, "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(a, "env", 4) == 0)
		return (1);
	else if (ft_strncmp(a, "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(a, "export", 7) == 0)
		return (1);
	else if (ft_strncmp(a, "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(a, "unset", 6) == 0)
		return (1);
	else
		return (0);
}
