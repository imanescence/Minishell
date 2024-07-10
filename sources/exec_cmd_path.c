/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:22:18 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/06/15 10:10:37 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*int	exec_cmd(t_data *data, char **args, char *path)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, data->env);
	else
	{
		waitpid(pid, 0, 0);
		return (0);
	}
	return (1);
}*/

int	find_cmd(t_data *data)
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
			data->pid = fork();
			if (data->pid == 0)
				execve(cmd, args, data->env);
			else
			{
				waitpid(data->pid, 0, 0);
				return (0);
			}
		}
		i++;
	}
	return (0);
}
