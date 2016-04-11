# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/19 17:36:29 by vquesnel          #+#    #+#              #
#*   Updated: 2016/03/28 13:29:25 by vquesnel         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =ft_atoi.c \
	 ft_bzero.c \
	 ft_isalnum.c \
	 ft_isalpha.c \
	 ft_isascii.c \
	 ft_isdigit.c \
	 ft_isprint.c \
	 ft_itoa.c \
	 ft_memalloc.c \
	 ft_memccpy.c \
	 ft_memchr.c \
	 ft_memcmp.c \
	 ft_memcpy.c \
	 ft_memdel.c \
	 ft_memmove.c \
	 ft_memset.c \
	 ft_putchar.c \
	 ft_putchar_fd.c \
	 ft_putendl.c \
	 ft_putendl_fd.c \
	 ft_putnbr.c \
	 ft_putnbr_fd.c \
	 ft_putstr.c \
	 ft_putstr_fd.c \
	 ft_strcat.c \
	 ft_strchr.c \
	 ft_strclr.c \
	 ft_strcmp.c \
	 ft_strcpy.c \
	 ft_strdel.c \
	 ft_strdup.c \
	 ft_strequ.c \
	 ft_striter.c \
	 ft_striteri.c \
	 ft_strjoin.c \
	 ft_strlcat.c \
	 ft_strlen.c \
	 ft_strmap.c \
	 ft_strmapi.c \
	 ft_strncat.c \
	 ft_strncmp.c \
	 ft_strncpy.c \
	 ft_strnequ.c \
	 ft_strnew.c \
	 ft_strnstr.c \
	 ft_strrchr.c \
	 ft_strsplit.c \
	 ft_strstr.c \
	 ft_strsub.c \
	 ft_strtrim.c \
	 ft_tolower.c \
	 ft_toupper.c \
	 ft_isspace.c \
	 ft_lstadd.c \
	 ft_lstdel.c \
	 ft_lstdelone.c \
	 ft_lstiter.c \
	 ft_lstmap.c \
	 ft_lstnew.c \
	 ft_swap.c \
	 ft_abs.c \
	 ft_clear_tab.c \
	 get_next_line.c

HEADER = ./includes
OBJ =  $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1m$(NAME) has been created\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[37mall libft_files.o are deleted\033[0m"
fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"
re: fclean all

.PHONY: all clean fclean re
