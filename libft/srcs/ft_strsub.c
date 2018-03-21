/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:28:06 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 23:55:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char *ret;

	if (!str || !(ret = ft_strnew(len)))
		return (NULL);
	ret = ft_strncpy(ret, str + start, len);
	return (ret);
}
