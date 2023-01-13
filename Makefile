# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 21:05:27 by wearaujo          #+#    #+#              #
#    Updated: 2023/01/13 21:05:30 by wearaujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_printf.c \
	  ft_pointer_fd.c \
	  ft_putchar_fd.c \
	  ft_putnbr_fd.c \
	  ft_puthex_num_fd.c \
	  ft_putstr_fd.c \
	  ft_putbase_fd.c \

OBJ = $(SRC:.c=.o)
%.o: %.c
	@cc $(FLAG) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "done"

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
