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
	b_helpers.c\
	op_store.c

OBJ = $(addprefix obj/,$(SRC:%.c=%.o))
DEP := $(OBJ:%.o=%.d)

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
CFLAGS = -Wall -Werror -Wextra -I libft
LDFLAGS = -L libft -lft -I libft

.PHONY: all clean fclean re bonus

all: $(LIBFT) $(NAME) bonus

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 

clean:
	/bin/rm -rf $(OBJDIR)
	make clean -C libft

fclean: clean
	/bin/rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BOBJ)
	cc -o $(BONUS_NAME) $(BOBJ) $(LDFLAGS)

docker:
	docker image build -t push_swap . && docker run --name push_swap -it push_swap

dockrm:
	docker rm push_swap && docker image rm push_swap