/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:30:28 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/12 07:14:02 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	slen;
	size_t	i;
	char	tmp;

	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	i = 0;
	while (i < slen)
	{
		tmp = str[i];
		str[i++] = str[--slen];
		str[slen] = tmp;
	}
	return (str);
}
