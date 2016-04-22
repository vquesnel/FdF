# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 13:03:29 by vquesnel          #+#    #+#              #
#    Updated: 2016/04/22 14:32:21 by vquesnel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= srcs/draw_line.c srcs/t_node_handling.c srcs/get_map.c srcs/main.c \
		 srcs/init_mlx.c srcs/searchinlist.c srcs/ft_isfdf.c srcs/tool.c \
		 srcs/key_hook.c srcs/t_coordmax_handling.c

OBJS= $(SRCS:.c=.o)
INCLUDES= -I libft/includes -I includes -I mlx/
LIBS= -L libft/ -lft -L mlx/ -lmlx
FLAGS= -Wall -Wextra -Werror
FRAMEWORK= -framework AppKit -framework OpenGL

$(NAME):	$(OBJS)
	@make -C libft/
	@make -C mlx/
	@gcc -o $(NAME) $(OBJS) $(LIBS) $(FRAMEWORK)
	@echo "\033[32;1m    __________  ______                                     __          \033[0m"
	@echo "\033[32;1m   / ____/ __ \/ ____/    ( )____     ________  ____ _____/ /_  __     \033[0m"
	@echo "\033[32;1m  / /_  / / / / /_       / / ___/    / ___/ _ \/ __ '/ __  / / / /     \033[0m"
	@echo "\033[32;1m / __/ / /_/ / __/      / (__  )    / /  /  __/ /_/ / /_/ / /_/ /      \033[0m"
	@echo "\033[32;1m/_/   /_____/_/        /_/____/    /_/   \___/\__,_/\__,_/\__, /       \033[0m"
	@echo "\033[32;1m                                                         /____/        \033[0m"



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
