/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_jumpat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:30:38 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:39:34 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_lst.h"

t_dc_lst_link	*ft_dclst_jumpat(t_dc_lst *dclst, size_t jmp)
{
	t_dc_lst_link *ret;

	if (!dclst)
		return (NULL);
	if (dclst->link_count < jmp + 1)
		return (dclst->tail);
	if (!jmp)
		return (dclst->head);
	if (dclst->link_count - (jmp + 1) < jmp)
	{
		ret = dclst->head;
		while (jmp--)
			ret = ret->next;
	}
	else
	{
		ret = dclst->tail;
		jmp = (jmp + 1) - dclst->link_count;
		while (jmp--)
			ret = ret->previous;
	}
	return (ret);
}
