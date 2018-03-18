/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:10:33 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 23:58:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(const char *str, char c)
{
	char	**splitted;
	size_t	wordcount;
	size_t	wordlen;
	size_t	i;

	if (!str)
		return (NULL);
	wordcount = ft_count_words(str, c);
	if (!(splitted = ft_arstrnew(wordcount)))
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		while (*str == c)
			str++;
		wordlen = ft_strclen(str, c);
		if (!(splitted[i++] = ft_strsub(str, 0, wordlen)))
			return (NULL);
		str = str + wordlen;
	}
	return (splitted);
}
