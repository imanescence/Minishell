/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:37 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/17 11:43:13 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*int	exe_export(struct s_cmd *struc)
{
	ft_printf("exe export\n");
	return (0);
}*/

// ---------------------- EXPORT -----------------------------------
//
// Mark each name to be passed to child processes in the environment.
//
// Failure Cases :
// 	* Undefined Variable: Attempting to export a variable that is not defined can result in a command failure
// 		Example : yoyo
// 		-> Return 0 / variable not created
// 		Example : yoyo=
// 		-> Return 0 ? variable created but no value assigned yoyo=$
//
// 	* Invalid Variable Name: Using an invalid variable name when exporting,
// 	such as using unauthorized special characters in variable names, can also lead to a failure
// 		Example : yoy*
// 		-> Return 1 / "bash: export: `yoy*': not a valid identifier"
// 		Example : yoy*=1
// 		-> Return 1 / "bash: export: `yoy*=1': not a valid identifier"
//
// 	* Permission Error: If you do not have the necessary permissions to export a variable,
// 	for example, if you try to export a variable in a directory where you do not have write permissions, this can result in a failure
// 		-> Return 1 ?? i guess
// 		-----------------  TRY THIS CASE WITH MODIF OF CHMOD OF BASHRC FILE !!!!!!!!!!
//
//
//azttntion avec les listes chainees si j'unset la premeire variable d'env de bien mettre a jour la tete de la liste chainees pour ne pas seg fault
//
//ATTENTION : faire une copie de l'envp dans un tableau pour pouvoir avoir une copie de l'environnement et pouvoir le modifier ou le supp par ex enlever l'env je ne dois plus pouvoir avoir acces aux cmd comme ls avec execve
//
//gerer aussi le cas de OLDPWD qui doit etre vide a chaque minishell lance puisque nouvel env pas d'ancien path mais DOIT exister tout de meme juste vide

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	**bubble_sort(t_data *data)
{
	int		i;
	int		j;
	char	**ar_sorted;

	ar_sorted = ar_dup_or_raised(data, data->env, NULL);
	i = 0;
	{
		j = 0;
		while (j < (data->nb_var - i) - 1)
		{
			if (j == data->nb_var -2)
				break ;
			if (strcmp(ar_sorted[j], ar_sorted[j + 1]) > 0)
				ft_swap(&ar_sorted[j], &ar_sorted[j + 1]);
			j++;
		}
		i++;
	}
	return (ar_sorted);
}

// AJOUTER STRCMP FAIT MAISON

void	free_char_ar(char **ar)
{
	int	i;

	i = 0;
	while (ar != NULL && ar[i])
	{
		free(ar[i]);
		ar[i] = NULL;
		i++;
	}
}

void	export_display(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->env_tmp = bubble_sort(data);
	while (data->env_tmp != NULL && data->env_tmp[i])
	{
		j = 0;
		write(1, "declare -x ", 11);
		while (data->env_tmp[i][j])
		{
			if (j && data->env_tmp[i][j - 1] == '=')
				break ;
			write (1, &data->env_tmp[i][j], 1);
			j++;
		}
		write(1, "\"", 1);
		while (data->env_tmp[i][j])
		{
			write(1, &data->env_tmp[i][j], 1);
			j++;
		}
		write(1, "\"\n", 2);
		i++;
	}
	free_char_ar(data->env_tmp);
}

void	var_adder(t_data *data)
{
	int	i;

	i = 0;
	data->env_tmp = ar_dup_or_raised(data, data->env, (*data->cmd)->str);
	free_char_ar(data->env);
	data->env = ar_dup_or_raised(data, data->env_tmp, NULL);
	free_char_ar(data->env_tmp);
}

int	exe_export(t_data *data)
{
	data->nb_input = count_str(data) - 1;
	if (data->nb_input > 0)
		var_adder(data);
	else
		export_display(data);
		// NE PAS OUBLIER DE FREE
		return (0);
	//}
	return (0);
}
