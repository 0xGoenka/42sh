# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 14:43:47 by eleclet           #+#    #+#              #
#*   Updated: 2017/03/09 00:32:31 by eleclet          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CFLAGS = -Werror -Wall -Wextra -g

SRC =	main.c		\
	error.c			\
	termcaps.c		\
	get_term_size.c	\
	string_man.c	\
	struct_op.c		\
	copyandpast.c	\
	historic.c 		\
	readline.c		\
	input_key.c		\
	input_key2.c	\
	input_key3.c	\
	sys.c 			\
	ux.c 			\
	outc.c			\
	ft_signal.c		\
	env.c			\
	parser.c		\
	disp_err.c		\
	exec.c			\
	sys_utils.c		\
	cd.c			\
	exit.c			\
	quotes.c		\
	somefunc.c		\
	binarytree.c	\
	ft_err.c		\
	dollar.c		\
	ft_sigwinch.c	\
	pipe.c			\
	parse_redir.c	\
	parse_redir2.c	\
	redir.c			\
	treat_red.c		\
	open_file.c		\
	heredoc.c		\
	parse_redir_2.c	\
	sys_ext.c		\
	binarytree_2.c	\
	env_ext.c		\
	ux_ext.c		\



OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft/
	gcc $(OBJ)  $(CFLAGS) -ltermcap -Llibft -lft -o $(NAME)
	@echo "$(NAME) built"

%.o: %.c header.h
	gcc -c $(CFLAGS) $<

clean :
	rm -rf $(OBJ)
	@make -C libft/ clean
fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean
re : fclean all
