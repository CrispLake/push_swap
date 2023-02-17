# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/02/17 17:12:12 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

SRC = $(NAME).c operations.c stack_creation.c sorting.c push_stack.c \
	  swap_stack.c rotate_stack.c reverse_rotate_stack.c b_helpers.c

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -L libft -lft -o $(NAME)

clean:
	rm -f $(OSRC)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/$(LIBFT)

%.o: %.c
	cc $(WWW) -c -o $@ $^ 

re: fclean all
