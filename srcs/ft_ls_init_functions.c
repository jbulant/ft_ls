/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_init_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:13:19 by jerome            #+#    #+#             */
/*   Updated: 2018/04/11 04:34:51 by jbulant          ###   ########.fr       */
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

int			init_env(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	if (!ft_stack_init(&env->dir_stack, MAX_DIR_STACK))
		return (0);
	return (1);
}
