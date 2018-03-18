/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arstrnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:19:56 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 05:20:24 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_arstrnew(size_t size)
{
	char **ar;

	if (!(ar = (char **)malloc((size + 1) * sizeof(char *))))
		return (NULL);
	ar[size] = NULL;
	return (ar);
}
