# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2024/04/12 17:47:03 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

LIBFT = libft/libft.a

SRCDIR = ./src
OBJDIR = ./obj

SRC =\
	main.c\
	operations.c\
	stack_creation.c\
	sort_a.c\
	sort_b.c\
	push_stack.c\
	swap_stack.c\
	rotate_stack.c\
	reverse_rotate_stack.c\
	b_helpers.c

OBJ = $(addprefix obj/,$(SRC:%.c=%.o))

BSRC =\
	checker_bonus.c\
	operations_bonus.c\
	stack_creation_bonus.c\
	push_stack_bonus.c\
	swap_stack_bonus.c\
	rotate_stack_bonus.c\
	reverse_rotate_stack_bonus.c\
	checker_helpers_bonus.c

BOBJ = $(addprefix obj/,$(BSRC:%.c=%.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Llibft -lft

.PHONY: all clean fclean re bonus

all: $(NAME) 

$(LIBFT):
	make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) 

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	/bin/rm -rf $(OBJDIR)
	make clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BOSRC)
	make -C libft
	cc $(CFLAGS) $(BOSRC) $(LDFLAGS) -o $(BONUS_NAME)