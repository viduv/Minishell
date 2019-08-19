# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viduvern <viduvern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/12 10:01:03 by viduvern          #+#    #+#              #
#    Updated: 2019/08/19 14:54:46 by viduvern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB = libft/libft.a
SRC =	srcs/main.c \
		srcs/dispatch.c \
		srcs/echo.c \
		srcs/cd.c \
		srcs/dir.c \
		srcs/set_env.c \
		srcs/unset_env.c \

FLAG = -Wall -Werror -Wextra -g
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

libft:
	@make -C libft/ re

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(CB)[Minishell] :$(CE) $(CG)Creating Library$(CE)";
	@cp libft/libft.a .
	@echo "$(CB)[Minishell] :$(CE) $(CG)Compiling minishell ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(SRC) $(LIB)

%.o: %.c
	@echo "$(CB)[Minishell] :$(CE) $(CG)Compiling $<$(CE)";
	@gcc $(FLAG) -c $< -o $@

clean: 
	@echo "$(CB)[Minishell] :$(CE) $(CG)Cleaning Library ...$(CE)";
	-@make -C libft nohdclean
	@echo "$(CB)[Minishell] :$(CE) $(CG)Cleaning Minishell objects$(CE)";
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "$(CB)[Minishell] :$(CE) $(CY)Cleaning Minishell ...$(CE)";
	@/bin/rm -f $(NAME)

totclean: fclean
	@make -C libft/ fclean

re: fclean all
	
total: fclean libft all

.PHONY: all clean fclean re libft
