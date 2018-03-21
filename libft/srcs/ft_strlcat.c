/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:47:39 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 07:37:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dlen;
	size_t slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size < dlen)
		return (slen + size);
	size -= dlen;
	while (*src && size > 1)
	{
		*(dst++ + dlen) = *src++;
		size--;
	}
	*(dst + dlen) = '\0';
	return (dlen + slen);
}
