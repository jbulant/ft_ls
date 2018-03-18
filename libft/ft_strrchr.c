/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:50:42 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 07:56:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t slen;

	slen = ft_strlen(s);
	while ((slen + 1) && s[slen] != (char)c)
		slen--;
	return ((s[slen] == (int)c) ? (char *)(s + slen) : NULL);
}
