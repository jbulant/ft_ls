/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:46:07 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 23:59:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	char	*ret;
	size_t	slen;

	if (!str)
		return (NULL);
	while (ft_iswhitespace(*str))
		str++;
	slen = ft_strlen(str);
	while (ft_iswhitespace(str[slen - 1]) && slen > 1)
		slen--;
	if (!(ret = ft_strsub(str, 0, slen)))
		return (NULL);
	return (ret);
}
