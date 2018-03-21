/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_iscolorhex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:30:24 by jbulant           #+#    #+#             */
/*   Updated: 2017/12/13 14:47:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_iscolorhex(char *s)
{
	size_t			slen;

	slen = ft_strlen(s);
	if (slen >= 3 && s[0] == '0' && s[1] == 'x')
		s += 2;
	slen = ft_strlen(s);
	if (slen > 6 || !slen)
		return (FALSE);
	while (*s)
	{
		if (!ft_ishexa(*s))
			return (FALSE);
		s++;
	}
	return (TRUE);
}
