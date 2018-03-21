/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_basevalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:38:26 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/10 18:43:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_basevalue(char value, char *base, int b_height)
{
	int b_value;

	b_value = 0;
	while (b_value < b_height)
	{
		if (value == base[b_value])
			break ;
		b_value++;
	}
	return (b_value);
}
