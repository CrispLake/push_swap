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

BONUS_NAME = checker

LIBFT = libft.a

SRC = $(NAME).c operations.c stack_creation.c sorting.c push_stack.c \
	  swap_stack.c rotate_stack.c reverse_rotate_stack.c b_helpers.c

OSRC = $(SRC:%.c=%.o)

BSRC = checker_bonus.c operations_bonus.c stack_creation_bonus.c \
	   push_stack_bonus.c swap_stack_bonus.c rotate_stack_bonus.c \
	   reverse_rotate_stack_bonus.c

BOSRC = $(BSRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OSRC)
	cc $(WWW) $(OSRC) -L libft -lft -o $(NAME)

clean:
	rm -f $(OSRC) $(BOSRC)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f libft/$(LIBFT)

%.o: %.c
	cc $(WWW) -c -o $@ $^ 

re: fclean all

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BOSRC)
	cc $(WWW) $(BOSRC) -L libft -lft -o $(BONUS_NAME)
