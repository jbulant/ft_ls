/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_byte.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 02:32:16 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/16 00:56:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_byte(t_byte byte)
{
	t_byte bits;

	bits = 1 << 7;
	while (bits)
	{
		if (byte & bits)
			ft_putchar('1');
		else
			ft_putchar('0');
		if (bits & (1 << 4))
			ft_putchar('\n');
		bits >>= 1;
	}
}
