# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 13:35:37 by vquesnel          #+#    #+#              #
#*   Updated: 2016/04/30 18:44:08 by kwiessle         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= srcs/main.c srcs/draw_one_line.c srcs/draw_line.c \
	 srcs/get_map.c srcs/get_max.c srcs/init_env.c \
	srcs/init_param.c srcs/searchinlist.c srcs/init_node.c srcs/init_img.c \
	srcs/menu.c srcs/menu_wings.c srcs/key_hook.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx -lm
FLAGS= -Wall -Wextra -Werror -O3 -Ofast -O2
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\n"
	@echo "	\033[48;30;1m     ______    ______   _         ____  __   \033[0m"
	@echo "	\033[48;30;1m    / ____/___/ / __/  (_)____   / __ \/ /__ \033[0m"
	@echo "	\033[48;33;1m   / /_  / __  / /_   / / ___/  / / / / //_/ \033[0m"
	@echo "	\033[48;33;1m  / __/ / /_/ / __/  / (__  )  / /_/ / ,<    \033[0m"
	@echo "	\033[48;32;1m /_/    \__,_/_/    /_/____/   \____/_/|_\   \033[0m"
	@echo "	\033[48;32;1m vquesnel                               2016 \033[0m"
	@echo "\n"

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

