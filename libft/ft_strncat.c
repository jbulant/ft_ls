/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:58:21 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 00:39:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t dlen;

	i = 0;
	dlen = ft_strlen(dst);
	while ((dst[dlen + i] = src[i]) && i < n)
		i++;
	dst[dlen + i] = '\0';
	return (dst);
}
