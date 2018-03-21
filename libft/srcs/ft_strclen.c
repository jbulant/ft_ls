/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:14:20 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 05:14:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strclen(const char *str, char c)
{
	size_t wordlen;

	wordlen = 0;
	while (str[wordlen] != c && str[wordlen])
		wordlen++;
	return (wordlen);
}
