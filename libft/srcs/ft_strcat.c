/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:24:12 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 03:57:20 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t dlen;
	size_t i;

	dlen = ft_strlen(dest);
	i = 0;
	while ((dest[dlen + i] = src[i]))
		i++;
	dest[dlen + i] = '\0';
	return (dest);
}
