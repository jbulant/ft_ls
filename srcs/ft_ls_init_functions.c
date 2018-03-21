/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_init_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:13:19 by jerome            #+#    #+#             */
/*   Updated: 2018/03/20 21:38:55 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_env_functions(t_env *env)
{
	static t_bool		(*scmpf[4])() = {scmpf_alpha
										, scmpf_alpha
										, scmpf_alpha_reverse
										, scmpf_alpha_reverse};

	env->sort_cmp_f = scmpf[env->sort_mode];
}

void		init_env(t_env *env)
{
	env->file_list = NULL;
	env->sort_mode = 0;
	env->filters = NO_FILTER;
}
