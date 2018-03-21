/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:14:41 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 02:59:03 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_byte *s;
	t_byte *d;
	size_t i;

	s = (t_byte *)src;
	d = (t_byte *)dest;
	i = 0;
	while (i < n)
	{
		if ((d[i] = s[i]) == (t_byte)c)
			return ((void *)d + ++i);
		i++;
	}
	return (NULL);
}
