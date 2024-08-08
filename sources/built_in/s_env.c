/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:12 by ssteveli          #+#    #+#             */
/*   Updated: 2024/08/01 13:38:23 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shlvl_updater(t_data *data)
{
	int	i;

	i = 0;
	data->shlvl++;
	while (data->env[i])
	{
		if (ft_strncmp("SHLVL=", data->env[i], 6) == 0)
		{
			free(data->env[i]);
			data->env[i] = NULL;
			data->env[i] = ft_strnjoin("SHLVL=", ft_itoa(data->shlvl));
			break ;
		}
		i++;
	}
}

void	old_pwd_update(t_data *struc, char *pwd)
{
	int	i;

	i = 0;
	while (struc->env[i])
	{
		if (ft_strncmp("OLDPWD", struc->env[i], 6) == 0)
		{
			free(struc->env[i]);
			struc->env[i] = NULL;
			struc->env[i] = ft_strnjoin("OLD", pwd);
		}
		i++;
	}
}

void	pwd_update(t_data *struc)
{
	int	i;

	i = 0;
	while (struc->env[i])
	{
		if (ft_strncmp("PWD=", struc->env[i], 4) == 0)
		{
			old_pwd_update(struc, struc->env[i]);
			free(struc->env[i]);
			struc->env[i] = NULL;
			struc->env[i] = ft_strnjoin("PWD=", getcwd(struc->buf, 100));
		}
		i++;
	}
}

int	exe_env(t_data *struc)
{
	int	i;

	i = 0;
	while (struc->env[i])
	{
		if (char_check(0, '=', struc->env[i]) != -1)
		{
			ft_putstr_fd(struc->env[i], struc->out_fd);
			write(struc->out_fd, "\n", 1);
		}
		i++;
	}
	ft_putstr_fd("_=/usr/bin/env\n", struc->out_fd);
	return (0);
}
