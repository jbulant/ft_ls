NAME = ft_ls

DEBUG = 1

LIBFTDIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFTDIR)$(LIBFT_NAME)
OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME = main.c \
			ft_error.c \
			arguments_checker.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft

LIBS = -L $(LIBFTDIR) -lft

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -lasan -g3

HEADERS_PATH = includes/
HEADERS_NAME = ft_ls.h ft_error.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADERS}
	@mkdir -p objs
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
	fi

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME);\
	fi

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all
