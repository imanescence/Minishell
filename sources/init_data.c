/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:03:33 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/20 18:03:35 by ssteveli         ###   ########.fr       */
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
		exit (EXIT_FAILURE); // protextion malloc
	while (path_tmp[j])
	{
		if (char_check(path_tmp[j], ':', NULL) == 0)
		{
			path_tmp[j] = '/';
			j++;
			data->paths[i] = ft_substr(path_tmp, k, j - k);
			k = j;
			i++;
		}
		j++;
	}
	data->paths[i] = NULL;
	free(path_tmp);
}

t_data	*init_env(t_data *struc, char **env, t_cmd **cmd)
{
	int	i;

	i = 0;
	struc->nb_var = 35;
	struc->env = (char **)malloc(struc->nb_var * sizeof(char *)); 
	if (!struc->env)
		exit(EXIT_FAILURE); // ECRIRE MSG ERREUR STRERROR ??
	while (i < struc->nb_var - 1 && env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			struc->env[i] = ft_strdup(env[i]);
			init_path(struc, i);
			i++;
		}
		if (ft_strncmp("SHLVL=", env[i], 6) == 0)
		{
			struc->env[i] = ft_strdup("SHLVL=2");
			i++;
		}
		if (ft_strncmp("OLDPWD=", env[i], 7) == 0)
		{
			struc->env[i] = ft_strdup("OLDPWD");
			i++;
		}
		struc->env[i] = ft_strdup(env[i]);
		i++;
	}
	struc->cmd = cmd;
	struc->env[i] = NULL;
	i = 0;
	while (struc->env[i])
	{
		if(ft_strncmp(struc->env[i], "USER", 4) == 0)
		{
			struc->user = ft_substr(struc->env[i], 13, (ft_strlen(struc->env[i]) - len_to_egal(struc->env[i]))); 
		}
		i++;
	}
	return (struc);
}
