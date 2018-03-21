NAME = ft_ls

DEBUG = 1

LIBFTDIR = libft/
FT_ADV_LSTDIR = ft_adv_lst/
LIBFT_NAME = libft.a
FT_ADV_LST_NAME = libft_adv_lst.a

LIBFT = $(LIBFTDIR)$(LIBFT_NAME)
FT_ADV_LST = $(FT_ADV_LSTDIR)$(FT_ADV_LST_NAME)

OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME = main.c \
			ft_error.c \
			arguments_checker.c \
			sort_cmp_functions.c \
			ft_ls_init_functions.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft/includes

LIBS = -L $(LIBFTDIR) -lft -L $(FT_ADV_LSTDIR) -lft_adv_lst

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
		echo [$(NAME)][DEBUG]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [$(NAME)]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	fi

$(LIBFT):
	@make -C $(LIBFTDIR)

$(FT_ADV_LST):
	@make -C $(FT_ADV_LSTDIR)

$(NAME): $(OBJS) $(LIBFT) $(FT_ADV_LST)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME);\
	fi
	@echo PROGRAM: $(NAME) HAS BEEN COMPILED.

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(FT_ADV_LSTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(FT_ADV_LSTDIR) fclean

re: fclean all
