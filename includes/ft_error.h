/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:24:05 by jerome            #+#    #+#             */
/*   Updated: 2018/03/20 00:50:33 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

#include <stdio.h>

# include <errno.h>
# include <stdlib.h>
# include "libft.h"

# define ERROR0		"-ft_ls: cannot access '%s': \n"
# define ERROR1		"-ft_ls: invalid option --'%c'\n"
# define ERROR2		"-ft_ls: '%s' is ambiguous; possibilities: \n"
# define ERROR3		"-ft_ls: unrecognized option '%s'\n"
# define ERROR4		""
# define ERROR5		""
# define ERROR6		""
# define ERROR7		""
# define ERROR8		""
# define ERROR9		""
# define ERROR10	""
# define ERROR11	""
# define ERROR12	""
# define ERROR13	""
# define ERROR14	""
# define ERROR15	""
# define ERROR16	""
# define ERROR17	""
# define ERROR18	""
# define ERROR19	""
# define ERROR20	""
# define ERROR21	""
# define ERROR22	""
# define ERROR23	""
# define ERROR24	""
# define ERROR25	""
# define ERROR26	""
# define ERROR27	""
# define ERROR28	""
# define ERROR29	""
# define ERROR30	"  Try './ft_ls --help' for more information.\n"

# define ERROR_ARRAY1	ERROR0, ERROR1, ERROR2, ERROR3, ERROR4, ERROR5, ERROR6
# define ERROR_ARRAY2	ERROR7, ERROR8, ERROR9, ERROR10, ERROR11, ERROR12
# define ERROR_ARRAY3	ERROR13, ERROR14, ERROR15, ERROR16, ERROR17, ERROR18
# define ERROR_ARRAY4	ERROR19, ERROR20, ERROR21, ERROR22, ERROR23, ERROR24
# define ERROR_ARRAY5	ERROR25, ERROR26, ERROR27, ERROR28, ERROR29, ERROR30

# define ERROR_ARRAY_GRP1	ERROR_ARRAY1, ERROR_ARRAY2, ERROR_ARRAY3
# define ERROR_ARRAY_GRP2	, ERROR_ARRAY4, ERROR_ARRAY5

# define ERROR_ARRAY	ERROR_ARRAY_GRP1 ERROR_ARRAY_GRP2
# define ERROR_WITHOUT_OPTION_INDEX 29

typedef enum	e_error_flags
{
	NO_REASON = 0,
	FILE_ACCESS = 1 << 0,
	INVALID_S_OPTION = 1 << 1,
	AMBIGUOUS_L_OPTION = 1 << 2,
	UNRECOGNIZED_L_OPTION = 1 << 3,
	SHOW_HELP_CMD_FOR_INFO = 1 << 30,
	FATAL_ERROR = 1 << 31
}				t_error_flags;

void		ft_error(t_error_flags flags, char *option);

#endif