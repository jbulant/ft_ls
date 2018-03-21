/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:55:11 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/12 04:11:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *str, const char *to_find)
{
	size_t flen;

	if (!*to_find)
		return ((char *)str);
	flen = ft_strlen(to_find);
	while (*str)
	{
		if (*str == *to_find
			&& !ft_memcmp((const void *)str, (const void *)to_find, flen))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
