/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@marvin.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 22:59:18 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/12 04:01:04 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t flen;

	if (!*to_find)
		return ((char *)str);
	flen = ft_strlen(to_find);
	while (*str && n-- >= flen)
	{
		if (*str == *to_find
			&& !ft_memcmp((const void *)str, (const void *)to_find, flen))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
