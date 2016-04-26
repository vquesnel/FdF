# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 13:35:37 by vquesnel          #+#    #+#              #
#    Updated: 2016/04/26 13:45:17 by vquesnel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= srcs/main.c srcs/

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx
FLAGS= -Wall -Wextra -Werror
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\n"
	@echo "\033[32;1m███████╗██████╗ ███████╗    ██╗███████╗    ██████╗ ███████╗ █████╗ ██████╗ ██╗   ██╗    \033[0m"
	@echo "\033[32;1m██╔════╝██╔══██╗██╔════╝    ██║██╔════╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗╚██╗ ██╔╝    \033[0m"
	@echo "\033[32;1m█████╗  ██║  ██║█████╗      ██║███████╗    ██████╔╝█████╗  ███████║██║  ██║ ╚████╔╝     \033[0m"
	@echo "\033[32;1m██╔══╝  ██║  ██║██╔══╝      ██║╚════██║    ██╔══██╗██╔══╝  ██╔══██║██║  ██║  ╚██╔╝      \033[0m"
	@echo "\033[32;1m██║     ██████╔╝██║         ██║███████║    ██║  ██║███████╗██║  ██║██████╔╝   ██║       \033[0m"
	@echo "\033[32;1m╚═╝     ╚═════╝ ╚═╝         ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝       \033[0m"
	@echo "\n"
	@echo "\033[32;1m Vquesnel									2016\033[0m"


$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:	$(NAME)

clean:
	@make -C libft/ clean
	@make -C mlx/ clean
	@rm -f $(OBJS)
	@echo "\033[37mall FdF_files.o are deleted\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[31m$(NAME) is deleted\033[0m"

re:		fclean all

.PHONY: all clean fclean re

