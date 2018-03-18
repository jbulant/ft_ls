/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:56:06 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/09 07:02:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret;

	if (!(ret = (char *)ft_memalloc(ft_strlen(src) + 1)))
		return (NULL);
	return (ft_strcpy(ret, src));
}
