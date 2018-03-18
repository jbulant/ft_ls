/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:10:30 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 05:09:10 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(const char *str, char separator)
{
	size_t wc;

	wc = 0;
	while (*str)
	{
		while (*str == separator)
			str++;
		if (!*str)
			break ;
		wc++;
		while (*str && *str != separator)
			str++;
	}
	return (wc);
}
