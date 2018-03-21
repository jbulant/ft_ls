/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexstr_to_byte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:31:29 by jbulant           #+#    #+#             */
/*   Updated: 2017/12/13 14:31:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_byte	ft_hexstr_to_byte(char *s)
{
	static char charset[17] = "0123456789abcdef";
	int			i;
	t_byte		ret;

	ret = 0;
	while (*s)
	{
		i = 0;
		while (*s != 'x' && *s != charset[i])
			i++;
		ret = i + (ret * 16);
		s++;
	}
	return (ret);
}
