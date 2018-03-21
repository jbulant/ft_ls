/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:03:47 by jbulant           #+#    #+#             */
/*   Updated: 2017/12/08 23:05:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_basecheck(char *base)
{
	char	ascii[128];

	if (ft_strlen(base) < 2)
		return (FALSE);
	ft_bzero(ascii, 128);
	while (*base)
	{
		if (!ft_isprint(*base) || ascii[(int)*base] == *base
			|| *base == '+' || *base == '-')
			return (FALSE);
		ascii[(int)*base] = *base;
		base++;
	}
	return (TRUE);
}
