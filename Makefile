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

NAME =    libftprintf.a

CC =    gcc

FLAGS =    -Wall -Werror -Wextra

FT_SRC_DIR =  ./includes

PRINTF_SRC_DIR = ./srcs

HEADER =   $(FT_SRC_DIR)libft.h

PRINTF_SRC_HEADER = $(PRINTF_SRC_DIR)ft_printf.h

FT_COMPILED =  ft_memset.o ft_bzero.o ft_memcpy.o \
	ft_memccpy.o ft_memmove.o ft_memchr.o ft_memcmp.o \
	ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o \
	ft_strrchr.o ft_strstr.o ft_strnstr.o ft_strcmp.o \
	ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o \
	ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o \
	ft_tolower.o ft_memalloc.o ft_memdel.o ft_strnew.o \
	ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o \
	ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
	ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o \
	ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o \
	ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o\
	ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o \
	ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
	ft_count_words.o ft_get_lengthword.o ft_getcountnum.o \
	ft_push.o ft_has_space.o

PRINTF_COMPILED =  adittion_pr.o ft_printf.o flag_and_print.o putnbr.o \
	useful.o useful_other.o workc.o workd.o workd_other.o \
	workls.o workls_other.o work_no_mat.o worko.o \
	workpercent.o workpointer.o workpointer_other.o \
	works.o worku.o workx.o workx_other.o check_flags.o

COMPILED = $(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm  -f $(NAME)

re: fclean all
