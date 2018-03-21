/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:31:06 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:31:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_lst.h"

t_dc_lst		*ft_dclst_merge(t_dc_lst *mainlst, t_dc_lst *to_insert)
{
	if (!mainlst)
		return (to_insert);
	if (!to_insert)
		return (mainlst);
	mainlst->tail->next = to_insert->head;
	if (to_insert->head->previous)
		ft_putendl(DCLST_WARNING_PREVIOUS);
	to_insert->head->previous = mainlst->tail;
	mainlst->tail = to_insert->tail;
	mainlst->link_count += to_insert->link_count;
	return (mainlst);
}
