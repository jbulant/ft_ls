/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 07:18:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/20 20:15:22 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
**	ft_strcmp_case:
**	do the same work as ft_strcmp, but takes a boolean option parameter
**	if 'sensitive' is set to TRUE; will return ft_strcmp
**	otherwise, every alpha characters will be set to to lowercase for check
*/

int		ft_strcmp_case(const char *s1, const char *s2, t_bool sensitive)
{
	size_t			i;

	if (sensitive)
		return (ft_strcmp(s1, s2));
	i = 0;
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i])
		i++;
	return (ft_tolower((unsigned char)s1[i])
			- ft_tolower((unsigned char)s2[i]));
}