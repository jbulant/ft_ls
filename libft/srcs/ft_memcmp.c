/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:12:11 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 07:45:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_byte *bs1;
	t_byte *bs2;
	size_t i;

	bs1 = (t_byte *)s1;
	bs2 = (t_byte *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (bs1[i] == bs2[i] && (i < n - 1))
		i++;
	return (bs1[i] - bs2[i]);
}
