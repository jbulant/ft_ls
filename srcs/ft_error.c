/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:41:37 by jerome            #+#    #+#             */
/*   Updated: 2018/03/18 22:48:48 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#include "ft_error.h"

void		ft_error(t_error_flags flags, char *option)
{
	static const char	*error_msgs[31] = {ERROR_ARRAY};
	int					i;

	i = -1;
	while(++i < 31)
	{
		if (flags & (1 << i) && error_msgs[i])
		{
			if (i == 1)
				printf(error_msgs[i], *option);
			else
				printf(error_msgs[i], option);
		}
	}
	if (flags & FATAL_ERROR)
		exit(1);
}
