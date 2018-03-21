#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/03/17 03:47:46 by jbulant          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft_adv_lst.a

LIBFTDIR = libft/
OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME = ft_dclst_newlink.c \
			ft_dclst_create.c \
			ft_dclst_merge.c \
			ft_dclst_jumpat.c \
			ft_dclst_insert.c \
			ft_dclst_push.c

LSRCS_NAME = 

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LOBJS = $(addprefix $(LIBFTDIR),$(LSRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p objs
	@echo compiling: `echo $< | rev | cut -d'/' -f1 | rev | cut -d'.' -f1`
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFTDIR)%.o: $(LIBFTDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJS) $(LOBJS)
	ar rc $(NAME) $(OBJS) $(LOBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
