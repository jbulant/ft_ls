#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/03/20 22:47:23 by jerome           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

DEBUG = 1

HEADERS_NAME = libft.h

SRCS_NAME = \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memclr.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strndup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strrealloc.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstjoin.c \
			ft_lstappend.c \
			ft_arstrnew.c \
			ft_count_words.c \
			ft_strclen.c \
			ft_strrev.c \
			ft_swap.c \
			ft_swap_addr.c \
			ft_isspace.c \
			ft_iswhitespace.c \
			ft_abs.c \
			ft_npow.c \
			ft_poweroftwo.c \
			ft_poweroften.c \
			ft_static_itoa.c \
			ft_basecheck.c \
			ft_get_basevalue.c \
			ft_atoi_base.c \
			ft_print_byte.c \
			ft_swap_byte.c \
			ft_hexstr_to_byte.c \
			ft_ishexa.c \
			ft_str_iscolorhex.c

OBJDIR = objs/
SRCSDIR = srcs/
HEADERS_PATH = includes/

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

CC = gcc
INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -lasan -g3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo LIBRARY: `echo $(NAME) | rev | cut -d '.' -f2 | rev` HAS BEEN COMPILED.

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADERS}
	@mkdir -p objs
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [`echo $(NAME) | rev | cut -d '.' -f2 | rev`][DEBUG]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [`echo $(NAME) | rev | cut -d '.' -f2 | rev`]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	fi

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
