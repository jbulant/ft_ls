/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:09:49 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 08:36:19 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int sign;

	while (ft_isspace((int)*str))
		str++;
	sign = (*str == '+' || *str == '-') ? 44 - *str++ : 1;
	result = 0;
	while (ft_isdigit(*str))
		result = (result * 10) + ((*str++) - '0');
	return (result * sign);
}
