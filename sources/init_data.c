/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:03:33 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/08/01 13:30:50 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_path(t_data *data, int n)
{
	char	*path_tmp;
	int		i;
	int		j;
	int		k;

	j = (char_check(0, '=', data->env[n]) + 1);
	k = j;
	i = 0;
	path_tmp = ft_strdup(data->env[n]);
	data->paths = (char **)malloc(9 * sizeof(char *));
	if (!data->paths)
		exit (EXIT_FAILURE);
	while (path_tmp[j++])
	{
		if (char_check(path_tmp[j], ':', NULL) == 0)
		{
			path_tmp[j] = '/';
			j++;
			data->paths[i] = ft_substr(path_tmp, k, j - k);
			k = j;
			i++;
		}
	}
	data->paths[i] = NULL;
	free(path_tmp);
}

int	env_special_cases(t_data *struc, char **env, int i)
{
	if (ft_strncmp("PATH=", env[i], 5) == 0)
	{
		struc->env[i] = ft_strdup(env[i]);
		init_path(struc, i);
		return (1);
	}
	if (ft_strncmp("OLDPWD=", env[i], 7) == 0)
	{
		struc->env[i] = ft_strdup("OLDPWD");
		return (1);
	}
	if (ft_strncmp("USER=", env[i], 5) == 0)
	{
		struc->user = ft_substr(env[i], 13,
				(ft_strlen(env[i]) - len_to_egal(env[i])));
		return (0);
	}
	return (0);
}

t_data	*init_env(t_data *struc, char **env, t_cmd **cmd)
{
	int	i;

	i = 0;
	struc->nb_var = 35;
	struc->shlvl = 2;
	struc->out_fd = STDOUT_FILENO;
	struc->env = (char **)malloc(struc->nb_var * sizeof(char *));
	if (!struc->env)
		exit(EXIT_FAILURE);
	while (i < struc->nb_var - 1 && env[i])
	{
		if (env_special_cases(struc, env, i) == 1)
			i++;
		struc->env[i] = ft_strdup(env[i]);
		i++;
	}
	struc->cmd = cmd;
	struc->env[i] = NULL;
	return (struc);
}
