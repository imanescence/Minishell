NAME			= minishell

BUILT_IN		=	$(addprefix ./sources/built_in/,\
					s_cd.c\
					cd_utils.c\
					s_echo.c\
					s_env.c\
					s_exit.c\
					s_export.c\
					s_pwd.c\
					s_unset.c\
					env_utils.c)

SRCS 			=	$(addprefix $(SRCS_DIR),\
					builtin_change.c \
					cmd_bis.c\
					cmd.c \
					error_return.c \
					exec_cmd_path.c \
					execut.c \
					expender.c \
					file_input.c\
					file_output.c\
					free_all.c \
					ft_split_mutan.c \
					init_data.c\
					minishell_bis.c \
					num_count.c\
					pipe.c\
					redirection_bis.c \
					redirection.c \
					s_minishell.c \
					s_token.c\
					split_utilses.c\
					str_utils.c)
					
					

OBJS		= ${SRCS:.c=.o} ${BUILT_IN:.c=.o}

READLINE_PATH 	= $(HOME)/homebrew/Cellar/readline/8.2.10/

INCLUDES		= ./include -I$(READLINE_PATH)/include

LFLAGS 			= -lreadline -lhistory -L$(READLINE_PATH)/lib

CFLAGS 			= -Wall -Werror -Wextra

LIBFT 			= libraries/Libft

SRCS_DIR		= ./sources/

all:		${NAME}

${NAME}:	${OBJS}
			@make -C $(LIBFT)
			@gcc $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a

%.o:		%.c
			@gcc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
			${RM} ${OBJS}
			@cd $(LIBFT) && make clean

fclean:		clean
			${RM} ${NAME}
			${RM} minishell
			${RM} a.out
			@cd $(LIBFT) && make fclean

re:			fclean all

.PHONY:			all clean fclean re  run
