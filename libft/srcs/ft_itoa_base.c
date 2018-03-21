/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:43:59 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/12 19:54:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nblen(unsigned int n, unsigned int b_height)
{
	size_t len;

	len = 0;
	while ((n /= b_height) > 0)
		len++;
	return (len);
}

char			*ft_itoa_base(int n, char *base)
{
	char			*str;
	unsigned int	nb;
	unsigned int	b_height;
	size_t			len;

	if (!ft_basecheck(base))
		return (NULL);
	nb = n < 0 ? (unsigned int)-n : (unsigned int)n;
	b_height = ft_strlen(base);
	len = nblen(nb, b_height) + ((n >= 0) ? 1 : 2);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	str[--len] = base[(nb % b_height)];
	while ((nb /= b_height))
		str[--len] = base[(nb % b_height)];
	return (str);
}
