# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 18:30:46 by opakhovs          #+#    #+#              #
#    Updated: 2017/10/25 19:11:58 by opakhovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS =  -Wall -Wextra -Werror

SOURCES = tet.c ft_readfile.c LIBFT2/ft_lstnew.c LIBFT2/ft_memdel.c LIBFT2/ft_putstr.c \
	LIBFT2/ft_strnew.c LIBFT2/ft_bzero.c LIBFT2/ft_memalloc.c LIBFT2/ft_memcpy.c \
	LIBFT2/ft_putchar.c mapping.c ft_tetadd.c

OBJ = $(SOURCES:.c=.o)

HEADERS = libft.h fillit.h

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SOURCES)

clean:
	@rm -f *.o LIBFT2/*.o

fclean: clean
	@rm  -f $(NAME)

re: fclean all
