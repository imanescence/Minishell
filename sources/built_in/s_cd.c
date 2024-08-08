/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:31:09 by ssteveli          #+#    #+#             */
/*   Updated: 2024/07/26 11:20:15 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_error_handler(int errnum, void *ptr, t_data *data)
{
	errnum = errno;
	(void) ptr;
	write(2, "bash: cd: ", 10);
	write(2, ptr, ft_strlen(ptr));
	write(2, ": No such file or directory\n", 28);
	return (data->exit_code = 1);
}

int	cd_oldpwd_viewer(t_data *data)
{
	int	i;
	int	j;

	i = index_tab_searcher(data->env, "OLDPWD", 6);
	if (i == -1 || ft_strlen(data->env[i]) < 6)
	{
		ft_putstr_fd("minishell : cd: OLDPWD not set\n", 2);
		return (data->exit_code = 1);
	}
	j = (char_check(0, '=', data->env[i]) + 1);
	while (data->env[i][j])
	{
		write(1, &data->env[i][j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}

int	cd_home(t_data *data)
{
	int		i;
	char	*home;

	i = index_tab_searcher(data->env, "HOME=", 5);
	if (i == -1)
		return (cd_error_handler(0, (*data->cmd)->str[1], data));
	home = ft_substr(data->env[i], 5, ft_strlen(data->env[i]) - 5);
	if (chdir(home) == -1)
	{
		free(home);
		return (cd_error_handler(0, "", data));
	}
	free(home);
	return (0);
}

int	exe_cd(t_data *data)
{
	int		i;

	i = 0;
	if ((*data->cmd)->str[1] == NULL
		|| ft_strncmp((*data->cmd)->str[1], "~", 1) == 0)
	{
		if (cd_home(data) == 0)
			return (0);
	}
	else if (ft_strncmp((*data->cmd)->str[1], "-", 1) == 0)
	{
		if (cd_oldpwd_viewer(data) == 0)
			return (0);
	}
	else
		if (chdir((*data->cmd)->str[1]) == -1)
			return (cd_error_handler(0, (*data->cmd)->str[1], data));
	pwd_update(data);
	return (0);
}
