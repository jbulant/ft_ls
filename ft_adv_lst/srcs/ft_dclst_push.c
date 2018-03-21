/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:26:00 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:26:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_lst.h"

void			ft_dclst_push_front(t_dc_lst *dclst, t_dc_lst *to_add)
{
	if (!dclst || !to_add || !to_add->link_count)
		return ;
	if (!dclst->link_count)
	{
		*dclst = *to_add;
		return ;
	}
	to_add->tail->next = dclst->head;
	dclst->head->previous = to_add->tail;
	dclst->head = to_add->head;
	dclst->link_count += to_add->link_count;
}

void			ft_dclst_push_back(t_dc_lst *dclst, t_dc_lst *to_add)
{
	if (!dclst || !to_add || !to_add->link_count)
		return ;
	if (!dclst->link_count)
	{
		*dclst = *to_add;
		return ;
	}
	to_add->head->previous = dclst->tail;
	dclst->tail->next = to_add->head;
	dclst->tail = to_add->tail;
	dclst->link_count += to_add->link_count;
}

void			ft_dclst_pushlink_front(t_dc_lst *dclst, t_dc_lst_link *to_add)
{
	if (!dclst || !to_add)
		return ;
	if (to_add->next)
		ft_putendl(DCLST_WARNING_NEXT);
	to_add->next = dclst->head;
	dclst->head = to_add;
	dclst->link_count++;
}

void			ft_dclst_pushlink_back(t_dc_lst *dclst, t_dc_lst_link *to_add)
{
	if (!dclst || !to_add)
		return ;
	dclst->tail->next = to_add;
	if (to_add->previous)
		ft_putendl(DCLST_WARNING_PREVIOUS);
	to_add->previous = dclst->tail;
	dclst->link_count++;
}
