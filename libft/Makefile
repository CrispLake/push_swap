# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/07/03 12:19:27 by emajuri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strrev.c ft_strmapi.c ft_striteri.c ft_strrev.c ft_itoa_base.c \
	  ft_ulltoa_base.c ft_putull_base_fd.c ft_lstnew_bonus.c \
	  ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
	  ft_lstiter_bonus.c ft_lstmap_bonus.c ft_printf.c ft_printf_fd.c \
	  ft_split_quote.c ft_split_one_malloc.c ft_realloc.c ft_get_next_line.c \
	  ft_get_next_line_utils.c ft_isspace.c

OSRC = $(SRC:%.c=%.o)

WWW = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OSRC)
	ar -rcs $(NAME) $(OSRC)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

%.o: %.c
	cc $(WWW) -c -o $@ $^

re: fclean all
