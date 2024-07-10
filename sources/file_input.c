/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:55:26 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/21 16:36:52 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	error_in(t_data *data)
{
	return(data->exit_code = 1);
}

int	mini_pars_in(t_data *data)
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
		data->out_fd = open(list->str, O_RDONLY);
			 if (data->out_fd == -1)
			 {
				 printf("euh pk\n");
		 		return (error_in(data));
			 }
		//list = list->next;
	//}
	return (0);
}

int	find_multi_cmd_in(t_data *data)
{
	char	**args;
	char	*cmd;
	int		i;

	i = 0;
	data->nb_input = count_str(data);
	args = ar_dup(data, (*data->cmd)->str);
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
			//	waitpid(data->pid, 0, 0);
		//		return (0);
		//	}
		}
		i++;
	}
	return (0);
}

int	infile_redirection(t_data *data)
{
	if (mini_pars_in(data) != 0)
		return (1);
	data->pid = fork();
	if (data->pid == -1)
	   return (error_in(data));	// proteger fork
	if (data->pid == 0)
	{
		printf("iciiii\n");
		if (dup2(data->out_fd, STDIN_FILENO) == -1)
			return (error_in(data));
		close(data->out_fd);
		find_multi_cmd_in(data);
	}
	else
	{
		close(data->out_fd);
		//close(STDIN_FILENO);
		waitpid(data->pid, 0, 0);
		printf("pas de return ??\n\n");
		return (0);
	}
	return (0);
}
