/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:29:11 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:29:57 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_lst.h"

void			ft_dclst_insert_at(t_dc_lst *mainlst, t_dc_lst *to_add
								, size_t jmp)
{
	t_dc_lst_link	*insert_at;

	if (!mainlst || !to_add || !to_add->link_count)
		return ;
	if ((insert_at = ft_dclst_jumpat(mainlst, jmp)))
	{
		if (jmp >= mainlst->link_count)
		{
			to_add->head->previous = insert_at;
			insert_at->next = to_add->head;
			mainlst->tail = to_add->tail;
			return ;
		}
		to_add->head->previous = insert_at->previous;
		to_add->tail->next = insert_at;
		insert_at->previous = to_add->tail;
		if (jmp == 0)
			mainlst->head = insert_at;
		mainlst->link_count += to_add->link_count;
		return ;
	}
	*mainlst = *to_add;
}

void			ft_dclst_insertlink_at(t_dc_lst *mainlst, t_dc_lst_link *to_add
									, size_t jmp)
{
	t_dc_lst_link	*insert_at;

	if (!mainlst || !to_add)
		return ;
	if ((insert_at = ft_dclst_jumpat(mainlst, jmp)))
	{
		if (jmp >= mainlst->link_count++)
		{
			to_add->previous = mainlst->tail;
			mainlst->tail->next = to_add;
			mainlst->tail = to_add;
			return ;
		}
		to_add->previous = insert_at->previous;
		insert_at->previous = to_add;
		to_add->next = insert_at;
		if (jmp == 0)
			mainlst->head = insert_at;
		return ;
	}
	*mainlst = (t_dc_lst){to_add, to_add, 1};
}
