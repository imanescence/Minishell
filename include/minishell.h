/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:46:32 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/18 14:30:06 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/Libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>

// **************** BUILT-IN *********************

int		exe_token(struct s_cmd *struc);
int		exe_cd(struct s_data *struc);
int		exe_echo(struct s_data *struc);
// ----------------- ENV -----------------------
int		exe_env(struct s_data *struc);
void	old_pwd_update(t_data *struc, char *pwd);
void	pwd_update(t_data *struc);
void	shlvl_updater(t_data *data);

int		exe_exit(struct s_data *struc);
// -------------- EXPORT ----------------------
int		exe_export(t_data *struc);

int		exe_pwd(struct s_data *struc);
int		exe_unset(struct s_data *struc);

// **************** BUILT-IN UTILS ****************

// -------- EXPORT ---------
void	export_display(t_data *struc);
char	**bubble_sort(t_data *struc);
void	ft_swap(char **a, char **b);

// -------- ENV ------------
char	**ar_dup_or_raised(t_data *data, char **original, char **new_strs);
char	*ft_strnjoin(char *s1, char *s2);
t_data	*init_env(t_data *data, char **env, t_cmd **cmd);
void	init_path(t_data *data, int i);
char	**ar_dup(t_data *data, char **tab);
char	**ar_dup_or_raised(t_data *data, char **original, char **new_strs);
void	raise_strs(t_data *data, char **new_ar, char**new_strs, int *ind);

// ------------ CD ---------------

void	ft_putstr_fd(char *s, int fd);
int		index_tab_searcher(char **tab, char *str, int len);

// ******************** EXEC **********************

// ------------ EXEC UTILS --------------------

int		count_str(t_data *data);
int		char_check(char cmp, char to_find, char *str);

// ----------------- CMD PATH ------------------

int		find_cmd(t_data *data);
int		find_multi_cmd(t_data *data);

// ----------------- REDIRECTIONS --------------

int		mini_pars_infile(t_data *data);
int		error_infile(t_data *data);
int		outfile_redirection(t_data *data);
int		infile_redirection(t_data *data);

// ------------------ PIPE --------------------

int		pipe_redirection(t_data *data);

//builtin_change
int		is_buitin(char *a);

//cmd_bis
t_list	*is_t(t_list **lexer);
char	**is_s(t_list **lexer);

//cmd
t_cmd	*get_cmds_bis(t_list *tl, t_cmd *tc, t_cmd *prev, t_list **lx);
int		get_cmds(t_list **lexer, t_cmd **cmds);
t_list	*is_token_bis(t_list	*tp, t_list *pv, t_list *ll);

//erro_return
void	error_return(int i, char *str);

//execut
void	execut(t_cmd **cmd, t_data *data);

//expender
char	*hextend(char *a, t_data *data);
int	len_to_egal(char *str);

//free_all
void	ft_lstdel_cmd(t_cmd **cmd);
int		free_all(t_list **lexer, t_cmd **cmd, char **str);

//ft_split_mutan
char	**ft_splite_mutan(char *str);

//minishell_bis
void	sign_handler(int code);
void	init_minishell(t_data **d, t_cmd ***c, t_list ***l, char **e);
int		launch_mini(char **str, t_data *data, t_cmd **cmd, t_list **lexer);

//num_count
int		num_count(char *str);

//redirection_bis
void	redirection_2(t_data *data);
void	redirection_3(t_cmd *cmd, t_data *data);
void	redirection_4(t_data *data);

//redirection
void	redirect(t_cmd *cmd, t_data *data);

//s_minishell
char	*rl_gets(char *text);
void	print_lexer(t_list **lexer);
void	print_cmd(t_cmd **cmd, t_data *data);
void	sig_here_doc(int code);
void	sign_handler(int code);

//s_token
void	sup_list2(t_list *temp_lexer);
void	get_lexer(t_list **lexer, char **a);
int		get_cmds(t_list **lexer, t_cmd **cmds);

//split_utilses
int		error_quot(void);
int		len_to_sep(char *str, int i, char c);

t_glob	g_glob;

#endif
