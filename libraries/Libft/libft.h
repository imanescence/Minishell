/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssteveli <ssteveli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:38:53 by ssteveli          #+#    #+#             */
/*   Updated: 2024/06/18 14:41:17 by iait-ouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define TO_PIPE 1
# define FROM_PIPE 0

typedef struct s_glob
{
	int				in_heredoc;
}	t_glob;

typedef struct s_data
{
	char			**env;
	int				nb_var;
	char			**env_tmp;
	char			buf[100];
	int				nb_input;
	int				shlvl;
	char			**paths;
	int				exit_code;
	pid_t			pid;
	int				out_fd;
	int				in_fd;
	int				pipe_fd[2];
	struct s_cmd	**cmd;
	char			*user;
}	t_data;

typedef enum e_token
{
	Not_a_token = 0,
	Pipe,
	TRUNC,
	APPEND,
	INPUT,
	HEREDOC,
	ERROR
}	t_token;

typedef enum e_type
{
	Token = 0,
	builtin,
	str
}	t_type;

typedef struct s_list
{
	int				i;
	char			*str;
	t_token			token;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_cmd
{
	char			**str;
	int				(*builtin)(struct s_data *);
	int				num_redirection;
	char			*hd_files_name;
	t_list			*redirection;
	int				fd_herdoc;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

size_t	ft_strlen(const char *str);
int		ft_isdigit(char *c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlenint(const int *str);
int		ft_strchr(char *a, int c, int j);
int		ft_atoi(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_printf(const char *a, ...);
void	*ft_bzero(void *a, size_t len);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		is_chr(char s);
int		is_str(char *s);
int		is_p(unsigned long s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		is_d(int nb);
int		is_u(unsigned int nb);
int		is_x(unsigned int s);
int		is_xup(unsigned int s);
int		len_s(unsigned long s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_toupper(int c);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *stack);
void	ft_lstadd_back(t_list **lst, t_list *news);
char	**ft_split(char const *s, char c);
t_list	*ft_lstnew(t_token token, char *str, int i, t_list *prev);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdel(t_list **alst);
t_cmd	*new_2(int (*bn)(struct s_data *), t_list *red, char **s, t_cmd *pv);
void	ft_lstadd_back2(t_cmd **lst, t_cmd *news);
void	ft_putstr_fd(char *s, int fd);
#endif
