/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:16:24 by jerome            #+#    #+#             */
/*   Updated: 2018/03/18 23:02:37 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>

# include "libft.h"
# include "ft_error.h"

# define HELP0	"Usage: ./ft_ls [OPTION]... [FILE]...\nList information about "
# define HELP1	"the FILEs (the current directory by default).\nSort entry alp"
# define HELP2	"habetically if none of -tu is specified.\n\nMandatory argumen"
# define HELP3	"ts to long options are mandatory for short options too.\n  -a"
# define HELP4	", --all         do not ignore entries starting with .\n  -d, "
# define HELP5	"--directory   list directory themselves, not their contents\n"
# define HELP6	"  -l                use a long listing format\n  -r, --revers"
# define HELP7	"e     reverse order while sorting\n  -R, --recursive   list s"
# define HELP8	"ubdirectories recursively\n  -t                sort by modifi"
# define HELP9	"cation time, newest first\n  -u                with -lt: sort"
# define HELP10	" by, and show, access time;\n                      with -l: s"
# define HELP11	"how access time and sort by name;\n                      othe"
# define HELP12	"rwise: sort by access time, and sort by name;\n"

# define HELP_GRP1 HELP0 HELP1 HELP2 HELP3 HELP4 HELP5 HELP6
# define HELP_GRP2 HELP7 HELP8 HELP9 HELP10 HELP11 HELP12

# define HELP	HELP_GRP1 HELP_GRP2

# define LONG_OPT_MAX	4
# define LONG_OPT_ALL	"--all"
# define LONG_OPT_REV	"--reverse"
# define LONG_OPT_DIR	"--directory"
# define LONG_OPT_REC	"--recursive"
# define LONG_OPTS		LONG_OPT_ALL, LONG_OPT_REV, LONG_OPT_DIR, LONG_OPT_REC
# define LONG_OPT_HELP	"--help"

typedef enum	e_ls_filter
{
	NO_FILTER = 0,
	ALL_FILES = (1 << 0),
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

typedef struct	s_env
{
	t_list		*file_list;
	t_ls_filter	filters;
	t_ls_sort	sort_mode;
}				t_env;

void			parse_arguments(t_env *env, char **args);

#endif