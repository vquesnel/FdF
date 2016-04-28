# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/26 13:35:37 by vquesnel          #+#    #+#              #
#*   Updated: 2016/04/27 23:54:56 by vquesnel         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= srcs/main.c srcs/draw_affine.c srcs/draw_line.c srcs/draw_vertical.c \
	 srcs/get_map.c srcs/get_max.c srcs/init_coord.c srcs/init_env.c \
	 srcs/init_mlx.c srcs/init_param.c srcs/init_proj.c srcs/searchinlist.c \
	 srcs/init_node.c srcs/key_hook.c srcs/menu.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx
FLAGS= -Wall -Wextra -Werror -O3 -Ofast -O2
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\033[41;37;1m     ______    ________   ____        ____                 __      \033[0m"
	@echo "\033[41;37;1m    / ____/___/ / ____/  /  _/____   / __ \___  ____ _____/ /_  __ \033[0m"
	@echo "\033[41;37;1m   / /_  / __  / /_      / // ___/  / /_/ / _ \/ __ '/ __  / / / / \033[0m"
	@echo "\033[41;37;1m  / __/ / /_/ / __/    _/ /(__  )  / _, _/  __/ /_/ / /_/ / /_/ /  \033[0m"
	@echo "\033[41;37;1m /_/    \__,_/_/      /___/____/  /_/ |_|\___/\__,_/\__,_/\__, /   \033[0m"
	@echo "\033[41;37;1m                                                         /____/    \033[0m"
	@echo "\033[31mvquesnel						       2016\033[0m"


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

