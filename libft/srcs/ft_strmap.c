/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:20:01 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 23:53:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char	*ret;
	size_t	i;

	if (!f || !(ret = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = f(str[i]);
		i++;
	}
	return (ret);
}
