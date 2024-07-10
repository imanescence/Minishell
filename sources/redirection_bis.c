/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:02:53 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/24 14:04:08 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	redirection_2(t_data *data)
{
	ft_printf("redirection 2\n");
	outfile_redirection(data);
}

void	redirection_3(t_cmd *cmd, t_data *data)
{
	(void)cmd;
	(void)data;
	ft_printf("redirection 3\n");
}

void	redirection_4(t_data *data)
{
	ft_printf("redirection 4\n");
	infile_redirection(data);
}
