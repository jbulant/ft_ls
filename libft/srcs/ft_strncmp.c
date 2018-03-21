/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:04:57 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/20 20:14:57 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
**	ft_strncmp_case:
**	do the same work as ft_strncmp, but takes a boolean option parameter
**	if 'sensitive' is set to TRUE; will return ft_strncmp
**	otherwise, every alpha characters will be set to to lowercase for check
*/

int		ft_strncmp_case(const char *s1, const char *s2
						, size_t n, t_bool sensitive)
{
	size_t			i;

	if (sensitive)
		return (ft_strncmp(s1, s2, n));
	if (!n)
		return (0);
	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] && i < n - 1)
		i++;
	return (ft_tolower((unsigned char)s1[i])
			- ft_tolower((unsigned char)s2[i]));
}