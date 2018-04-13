NAME = ft_ls

LINUX = 0
DEBUG = 0

LIBFTDIR = libft/
LIBFT_NAME = libft.a

LIBFT = $(LIBFTDIR)$(LIBFT_NAME)

OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME = main.c \
			ft_error.c \
			arguments_checker.c \
			sort_cmp_functions.c \
			ft_ls_init_functions.c \
			ft_stack.c \
			ft_awstr.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft/includes

LIBS = -L $(LIBFTDIR) -lft

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3
#DEBUGFLAGS = -fsanitize=address -lasan -g3

HEADERS_PATH = includes/
HEADERS_NAME =	ft_ls.h \
				ft_error.h \
				ft_stack.h \
				ft_awstr.h

HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADERS}
	@mkdir -p objs
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [$(NAME)][DEBUG]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [$(NAME)]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	fi

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS);\
	fi
	@echo PROGRAM: $(NAME) HAS BEEN COMPILED.

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@cd $(LIBFTDIR) && make clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all
