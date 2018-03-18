/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 06:51:21 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/10 21:32:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_byte *buffer;
	t_byte pattern;

	buffer = (t_byte *)b;
	pattern = (t_byte)c;
	while (len--)
		buffer[len] = pattern;
	return ((void *)buffer);
}
