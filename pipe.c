/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:53:39 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/07/05 17:36:20 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	find_multi_cmd_pipe(t_data *data, t_cmd *cmds)
{
	//char	**args;
	char	*cmd;
	int		i;

	i = 0;
	//data->nb_input = count_str();
	//args = ar_dup(data, cmds->str);
	int l = 0;
	while (cmds->str[l] != NULL)
	{
	//	printf(" strings avant le path %s\n\n", cmds->str[l]);
		l++;
	}
	while (data->paths[i])
	{
		cmd = ft_strnjoin(data->paths[i], cmds->str[0]);
	//	printf("ici 1\n");
		if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
		{
	//		printf("ici 2\n");
			//data->pid = fork();
			//if (data->pid == 0)
				execve(cmd, cmds->str, data->env);
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

int	link_lists_counter(t_data *data)
{
	int		i;
	t_cmd *cmds;

	i = 0;
	cmds = (*data->cmd);
	while (cmds != NULL)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}

int	waiting_children(int nb_cmd)
{
	int	i;

	i = 0;
	while (i < nb_cmds)
	{
		wait(NULL);
		i++;
	}
	return (0);
}

int	first_pipe(t_data *data, t_cmd *cmds, int nb_cmds)
{
	pipe(data->pipe_fd);
	data->pid = fork();
	if (data->pid == 0)
	{
		printf("\n\nj'entre dans le fork\n");
		close(data->pipe_fd[FROM_PIPE]);
		printf("jai close le fd from pipe donc le FD read de la pipe\n");
		dup2(data->pipe_fd[TO_PIPE], STDOUT_FILENO);
		printf("jai dup2\n");
		find_multi_cmd_pipe(data, cmd_obj);
	}
	else
	{
		close(data->pipe_fd[TO_PIPE];
		cmd = cmd->next;
		waiting_children(nb_cmds);
	}
	return (0);
}

int	multi_pipe(t_data *data)
{
	t_cmd	*cmds;
	int		i;
	int		nb_cmds;

	i = 0;
	cmds = (*data->cmd);
	nb_cmds = link_lists_counter(data);
	first_pipe(data, cmds, nb_cmds);
	i++;
	while (i < nb_cmds)
	{
		if (i == nb_cmds - 1)
			last_pipe(data, cmds);
		prv_fd = data->pipe_fd[0]; // le fd est de 4 ou 3 par ex cest l'int contenu a lindex 0 du tab d'int de pipei
									// le 0 est READ FROM le 1 WRITE TO

	}
	
}

int	pipe_redirection(t_data *data)
{
	int i = 0;
	t_cmd *cmd_obj;
	
	cmd_obj = (*data->cmd);
		while (cmd_obj->str[i] != NULL)
		{
	//		printf("heyyy %s\n", cmd_obj->str[i]);
			i++;
		}

	pipe(data->pipe_fd);
	data->pid = fork();
	if (data->pid == 0)
	{
		printf("\n\nj'entre dans le fork\n");
		close(data->pipe_fd[FROM_PIPE]);
		printf("jai close le fd from pipe donc le FD read de la pipe\n");
		dup2(data->pipe_fd[TO_PIPE], STDOUT_FILENO);
		printf("jai dup2\n");
		find_multi_cmd_pipe(data, cmd_obj);
	}
	else
	{
		printf("parent\n");
		wait(NULL);
		close(data->pipe_fd[TO_PIPE]);
		cmd_obj = cmd_obj->next;
	//	printf("heyyy %s\n", cmd_obj->str[0]);
	}
	/*data->pid = fork();
	if (data->pid == 0)
	{
		dup2(data->pipe_fd[FROM_PIPE], STDIN_FILENO);
		find_multi_cmd_pipe(data, cmd_obj);
	}
	else
	{
		wait(NULL);
		close(data->pipe_fd[FROM_PIPE]);
	}
	//		printf("ici 3\n");*/
	return (0);
}
