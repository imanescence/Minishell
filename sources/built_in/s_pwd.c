/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:41:50 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:59 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exe_pwd(t_data *data)
{
	ft_putstr_fd(getcwd(data->buf, 100), data->out_fd);
	write(data->out_fd, "\n", 1);
	return (0);
}
