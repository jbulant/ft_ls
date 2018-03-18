/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 00:39:40 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 03:33:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte *uc;
	size_t i;

	uc = (t_byte *)s;
	i = 0;
	while (i < n)
	{
		if (uc[i] == (t_byte)c)
			return ((void *)uc + i);
		i++;
	}
	return (NULL);
}
