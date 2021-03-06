/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:32:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/13 20:34:46 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_flst(void)
{
	return ((t_file*)ft_memalloc(sizeof(t_file)));
}

t_file		*flstdup(t_file *src)
{
  t_file	*dup;

  if (!(dup = new_flst()))
    return (NULL);
  return (ft_memcpy(dup, src, sizeof(t_file)));
}

t_long_file	*new_lflst(void)
{
	return ((t_long_file*)ft_memalloc(sizeof(t_long_file)));
}

void flst_add(t_file **aflst, t_file *new) {
	if (!aflst || !new)
		return ;
	new->next = (void*)*aflst;
	*aflst = new;
}
