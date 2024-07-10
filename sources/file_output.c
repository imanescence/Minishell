/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:21:22 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/18 14:45:00 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// PLUSIEURS FICHIERS avant la redirections :
// -> si ils existent deja a part le premier a droite de la redirection tout est redirige vers
// -> si ils existent aps cmd dit "no such file or directory" mais premier a droite cree et a du
// contenu
//

int	error_out(t_data *data)
{
	return(data->exit_code = 1);
}

int	mini_pars_out(t_data *data)
{
	//int	out_fd;
	int	i;
	t_list *list;

	i = 0;
	list = (*data->cmd)->redirection;
	printf("%s|\n", (*data->cmd)->redirection->str);
	//while (list)
	//{
		ft_printf("list str = %s\n", list->str);
		ft_printf("list token = %d\n", list->token);
		list = list->next;
		ft_printf("ICIIIIIII list str = %s\n", list->str);
		data->out_fd = open(list->str, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			 if (data->out_fd == -1)
			 {
				 printf("euh pk\n");
		 		return (error_out(data));
			 }
		//list = list->next;
	//}
	return (0);
}

int	find_multi_cmd(t_data *data)
{
	char	**args;
	char	*cmd;
	int		i;

	i = 0;
	data->nb_input = count_str(data);
	args = ar_dup(data, (*data->cmd)->str);
	int l = 0;
	while ((*data->cmd)->str[l] != NULL)
	{
		printf(" strings avant le path %s\n\n", (*data->cmd)->str[l]);
		l++;
	}
	while (data->paths[i])
	{
		cmd = ft_strnjoin(data->paths[i], (*data->cmd)->str[0]);
		if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
		{
			//data->pid = fork();
			//if (data->pid == 0)
				execve(cmd, args, data->env);
			//else
		//	{
		//		waitpid(data->pid, 0, 0);
		//		return (0);
		//	}
		}
		i++;
	}
	return (0);
}

int	outfile_redirection(t_data *data)
{
	if (mini_pars_out(data) != 0)
		return (1);
	data->pid = fork();
	if (data->pid == -1)
	   return (error_out(data));	// proteger fork
	if (data->pid == 0)
	{
		printf("iciiii\n");
		if (dup2(data->out_fd, STDOUT_FILENO) == -1)
			return (error_out(data));
		close(data->out_fd);
		find_multi_cmd(data);
	}
	else
	{
		close(data->out_fd);
		waitpid(data->pid, 0, 0);
		return (0);
	}
	return (0);
}

