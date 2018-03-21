/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmp_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:01:34 by jerome            #+#    #+#             */
/*   Updated: 2018/03/20 21:06:49 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool			scmpf_alpha_reverse(const char *s1
									, const char *s2
									, t_bool case_sensitive)
{
	return (ft_strcmp_case(s1, s2, case_sensitive) < 0 ? TRUE : FALSE);
}

t_bool			scmpf_alpha(const char *s1
							, const char *s2
							, t_bool case_sensitive)
{
	return (ft_strcmp_case(s1, s2, case_sensitive) > 0 ? TRUE : FALSE);
}
