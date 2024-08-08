/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:56:18 by iait-ouf          #+#    #+#             */
/*   Updated: 2024/08/06 13:50:19 by ssteveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_case(t_data *data, t_cmd *cmds)
{
	char	*pwd;

	if (ft_strncmp((*data->cmd)->str[0], "./", 2) == 0)
	{
		pwd = ft_strnjoin(getcwd(data->buf, 100),
				ft_substr((*data->cmd)->str[0],
					1, ft_strlen((*data->cmd)->str[0])));
		execve(pwd, cmds->str, data->env);
	}
	else if (ft_strncmp((*data->cmd)->str[0], "minishell", 9) == 0)
	{
		pwd = ft_strnjoin(getcwd(data->buf, 100),
				ft_strnjoin("/", (*data->cmd)->str[0]));
		execve(pwd, cmds->str, data->env);
	}
}

void	sign_quit(int code)
{
	char	*str;

	str = ft_itoa(code);
	write(2, "Quit: ", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int	existing_path_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp("PATH=", data->env[i], 5) == 0)
			return (0);
		i++;
	}
	ft_printf("%s: minishell: command not found\n", (*data->cmd)->str[0]);
	exit(127);
}

/*int	path_builder(t_data *data)
{
	char	*cmd;
	int		i;
	int		j;
	int		n;

	i = 0;
	while (ft_strncmp(data->env[i], "PATH=", 5) != 0)
	   i++;
	j = (char_check(0, '=', data->env[i]) + 1);
	n = j;
	while (data->env[i][j])
	{
		if (char_check(data->env[i][j], ':', NULL) != 1)
		{
			data->env[i][j] = '/';
			j++;
			cmd = ft_substr(data->env[i], n, j - n);
			cmd = ft_strjoin(cmd, data->cmd->str[1]);
			if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
				execve(cmd, args, data->env);
			n = j;
		}
		j++;
	}
	return (0);
}*/

// Reprendre lidee de depart en join selon ce quil y a dans le path 
// deja check voir si le path existe si oui return l'index du path dans l'env 
// recuperer l'index puis join avec les substr des path diff si access XOK et FOK envoyer dans find cmd
// et execve si non, return -1 ou quoi faire un if en consequences dans find cmd et printf cmd not found + exit 127

int	find_cmd(t_data *data, t_cmd *cmds)
{
	char	*cmd;
	int		i;

	i = 0;
	if (access(cmds->str[0], F_OK) == 0 && access(cmds->str[0], X_OK) == 0)
		execve(cmds->str[0], cmds->str, data->env);
	while (data->paths[i])
	{
		cmd = ft_strnjoin(data->paths[i], cmds->str[0]);
		if (access(cmd, F_OK) == 0 && access(cmd, X_OK) == 0)
			execve(cmd, cmds->str, data->env);
		else if (ft_strncmp((*data->cmd)->str[0], "./", 2) == 0)
			minishell_case(data, cmds);
		else if (ft_strncmp((*data->cmd)->str[0], "minishell", 9) == 0)
			minishell_case(data, cmds);
		i++;
	}
	ft_printf("%s: minishell: command not found\n", (*data->cmd)->str[0]);
	exit(127);
}

void	redirection_check(t_data *data, t_cmd *cmds)
{
	if (cmds->redirection->token == TRUNC
		|| cmds->redirection->token == APPEND)
	{
		outfile_redirection(data, cmds);
	}
	if (cmds->redirection->token == INPUT
		|| cmds->redirection->token == HEREDOC)
	{
		infile_redirection(data, cmds);
	}
}

int	one_command(t_data *data)
{
	t_cmd	*cmds;
	int		status;

	cmds = (*data->cmd);
	signal(SIGQUIT, &sign_quit);
	g_glob.in_heredoc = 1;
	data->pid = fork();
	if (data->pid == 0)
	{
		if (cmds->redirection)
			redirection_check(data, cmds);
		if (!cmds->str[0])
			exit(0);
		if (existing_path_check(data) == 0)
			find_cmd(data, cmds);
	}
	else
	{
		waitpid(data->pid, &status, 0);
		data->exit_code = WEXITSTATUS(status);
	}
	signal(SIGQUIT, SIG_IGN);
	g_glob.in_heredoc = 0;
	return (0);
}
