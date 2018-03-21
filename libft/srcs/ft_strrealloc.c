/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:46:33 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/23 16:48:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char **dst, size_t new_size)
{
	char *tmp;

	if (!dst || !(tmp = ft_strnew(new_size)))
		return (NULL);
	if (new_size > ft_strlen(*dst))
		ft_strcpy(tmp, *dst);
	else
		ft_strncpy(tmp, *dst, new_size);
	ft_strdel(dst);
	*dst = tmp;
	return (*dst);
}
