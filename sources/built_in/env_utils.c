/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:27:48 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/15 09:48:14 by iait-ouf         ###   ########.fr       */
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
		exit(1); // ET FREE EN CONSEQUENCES -> data->env[i] toutes les str
	while (ind[0] < data->nb_var - 1 && original[ind[0]])
	{
		new_ar[ind[0]] = ft_strdup(original[ind[0]]);
		ind[0]++;
	}
	if (new_strs != NULL)
		raise_strs(data, new_ar, new_strs, ind);
	new_ar[ind[0]] = NULL;
	return (new_ar);
}
