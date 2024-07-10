/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:47:19 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/15 10:47:25 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	index_tab_searcher(char **tab, char *str, int len)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], str, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}
