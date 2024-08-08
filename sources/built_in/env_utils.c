/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:27:48 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/08/08 15:58:24 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	raise_strs(t_data *data, char **new_ar, char **new_strs, int *ind)
{
	while (new_strs != NULL && new_strs[ind[1]])
	{
		new_ar[ind[0]] = ft_strdup(new_strs[ind[1]]);
		ind[0]++;
		ind[1]++;
		data->nb_var++;
	}
	new_ar[ind[0]] = NULL;
}

int	existing_var_check(char *var_env, char **new_strs, char **new_ar, int j)
{
	int	i;

	i = 0;
	if (!new_strs)
		return (-1);
	while (new_strs && new_strs[i])
	{
		if (ft_strncmp(var_env, new_strs[i], ft_strlen(new_strs[i])) == 0
			/*|| ft_strncmp(var_env, new_strs[i], char_check(0, '=', var_env)) == 0*/)
		{
			new_ar[j] = ft_strdup(new_strs[i]);
			return (0);
		}
		i++;
	}
	return (-1);
}
	

char	**ar_dup_or_raised(t_data *data, char	**original, char **new_strs)
{
	int		ind[2];
	char	**new_ar;

	ind[1] = 1;
	ind[0] = 0;
	new_ar = (char **) malloc ((data->nb_var + data->nb_input + 1)
			* sizeof(char *));
	if (!new_ar)
		exit(1);
	while (ind[0] < data->nb_var - 1 && original[ind[0]])
	{
		if (existing_var_check(original[ind[0]], new_strs, new_ar, ind[0]) != -1)
			ind[0]++;
		new_ar[ind[0]] = ft_strdup(original[ind[0]]);
		ind[0]++;
	}
	if (new_strs != NULL)
		raise_strs(data, new_ar, new_strs, ind);
	return (new_ar);
}
