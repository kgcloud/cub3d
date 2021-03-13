# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cloud <cloud@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 15:35:45 by cloud             #+#    #+#              #
#    Updated: 2021/03/13 16:15:27 by cloud            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = checkmap.c \
ft_error.c \
get_next_line.c \
get_next_line_utils.c \
init_struct.c \
parsing_utils.c \
print.c \
realloc.c \
start.c \
transit.c \

OBJ = ${SRC:.c=.o}

NAME = cub.a

LINK = ar rc

$(NAME):		$(OBJ)
	$(LINK)		$(NAME) 	$(OBJ)

all:		$(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)