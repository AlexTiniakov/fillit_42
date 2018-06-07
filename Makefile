# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 15:14:51 by otiniako          #+#    #+#              #
#    Updated: 2018/04/13 11:56:02 by anhloba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_create_list.c ft_error.c ft_memdel.c ft_open_read_tetr.c ft_strnew.c\
	main.c ft_memset.c ft_strlen.c ft_map.c ft_sqrt.c ft_print_rez.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) *.o

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all