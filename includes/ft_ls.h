/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:16:24 by jerome            #+#    #+#             */
/*   Updated: 2018/03/20 22:44:30 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>

# define THIS_DIR "."
# define PARENT_DIR ".."

# include <sys/stat.h>
# include <dirent.h>
# include "libft.h"
# include "ft_error.h"

# define HELP0	"Usage: ./ft_ls [OPTION]... [FILE]...\nList information about "
# define HELP1	"the FILEs (the current directory by default).\nSort entry alp"
# define HELP2	"habetically if -t is not specified.\n\nMandatory argumen"
# define HELP3	"ts to long options are mandatory for short options too.\n  -a"
# define HELP4	", --all         do not ignore entries starting with .\n  -d, "
# define HELP5	"--directory   list directory themselves, not their contents\n"
# define HELP6	"  -l                use a long listing format\n  -r, --revers"
# define HELP7	"e     reverse order while sorting\n  -R, --recursive   list s"
# define HELP8	"ubdirectories recursively\n  -t                sort by modifi"
# define HELP9	"cation time, newest first\n"

# define HELP_GRP1 HELP0 HELP1 HELP2 HELP3 HELP4 HELP5 HELP6
# define HELP_GRP2 HELP7 HELP8 HELP9

# define HELP	HELP_GRP1 HELP_GRP2

# define LONG_OPT_MAX	4
# define LONG_OPT_ALL	"--all"
# define LONG_OPT_REV	"--reverse"
# define LONG_OPT_DIR	"--directory"
# define LONG_OPT_REC	"--recursive"
# define LONG_OPTS		LONG_OPT_ALL, LONG_OPT_REV, LONG_OPT_DIR, LONG_OPT_REC
# define LONG_OPT_HELP	"--help"

# define OPT_LETTERS			"aldRtr"
# define OPT_MAX				6
# define OPT_FIRST_SORT_LETTER	4

typedef enum	e_ls_filter
{
	NO_FILTER = 0,
	ALL_FILES = (1 << 0),
	LIST_FILES = (1 << 1),
	DIRECTORY = (1 << 2),
	RECURSIVE = (0 << 3)
}				t_ls_filter;

typedef enum	e_ls_sort
{
	NAME = 0,
	TIME_MODIFICATION = 1,
	REVERSE = 2
}				t_ls_sort;

typedef struct	s_const_buffer
{
	char	*buffer;
	size_t	size;
}				t_const_buffer;

typedef struct	s_file
{
	struct dirent	*elem;
	struct stat 	info;
}				t_file;

# define MAX_DIR_STACK 128

typedef struct	s_dir_stack
{
	struct t_dirent		*files[MAX_DIR_STACK];
	t_bool				delete_me;
	size_t				size;
	struct s_dir_stack	*next;
}				t_dir_stack;

typedef struct	s_env
{
	t_dir_stack	dir_stack;
	t_list		*file_list;
	t_ls_filter	filters;
	t_ls_sort	sort_mode;
	t_bool		(*sort_cmp_f)();
}				t_env;

void			init_env(t_env *env);
void			parse_arguments(t_env *env, char **args);
void			init_env_functions(t_env *env);

t_bool			scmpf_alpha_reverse(const char *s1
									, const char *s2
									, t_bool case_sensitive);
t_bool			scmpf_alpha(const char *s1
							, const char *s2
							, t_bool case_sensitive);
#endif