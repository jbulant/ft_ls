/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:03:47 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/12 08:01:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_strbasecheck(char *str, char *base)
{
	int i;

	if (!ft_basecheck(base))
		return (FALSE);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		i = 0;
		while (base[i])
		{
			if (*str == base[i])
				break ;
			i++;
		}
		if (!base[i])
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int				ft_atoi_base(char *str, char *base)
{
	long	result;
	int		b_height;
	int		sign;

	if (!ft_strbasecheck(str, base))
		return (0);
	result = 0;
	b_height = ft_strlen(base);
	sign = 1;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	while (*str)
		result = result * b_height + ft_get_basevalue(*str++, base, b_height);
	return (((int)result) * sign);
}
