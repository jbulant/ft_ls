/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 06:29:59 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/10 21:33:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_byte *d;
	t_byte *s;
	size_t i;

	i = 0;
	d = (t_byte *)dest;
	s = (t_byte *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
