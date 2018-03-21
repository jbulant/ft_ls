/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 22:05:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:24:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_lst.h"

t_dc_lst_link	*ft_dclst_newlink(size_t ltype, size_t content_cnt)
{
	t_dc_lst_link	*ret;
	size_t			content_size;

	content_size = ltype * content_cnt;
	if (!(ret = ft_memalloc(sizeof(t_dc_lst_link) + content_size)))
		return (NULL);
	ret->ltype = ltype;
	ret->content_cnt = content_cnt;
	ret->content_size = content_size;
	return (ret);
}

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
		jmp = (jmp + 1) - dcst->link_count;
		while (jmp--)
			ret = ret->previous;
	}
	return (ret);
}

//		<dule> <dule1>
//		<truc-1> <truc> <truc1>
//		<truc-1> <dule> <dule1> <truc> <truc1>
//		insert_at->previous : to_add->head ~~ to_add->tail : insert_at : insert_at->next
void			ft_dclst_insert_at(t_dc_lst *mainlst, t_dc_lst *to_add, size_t jmp)
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

//		<dule> <dule1>
//		<truc-1> <truc> <truc1>
//		<truc-1> <dule> <dule1> <truc> <truc1>
//		insert_at->previous : to_add : insert_at : insert_at->next
void			ft_dclst_insertlink_at(t_dc_lst *mainlst, t_dc_lst_link *to_add, size_t jmp)
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

t_dc_lst_link	*ft_dclst_gettail(t_dc_lst_link *dclst_link)
{
	if (!dclst_link)
		return (NULL);
	while (dclst_link->next)
		dclst_link = dclst_link->next;
	return (dclst_link);
}

t_dc_lst_link	*ft_dclst_gethead(t_dc_lst_link *dclst_link)
{
	if (!dclst_link)
		return (NULL);
	while (dclst_link->previous)
		dclst_link = dclst_link->previous;
	return (dclst_link);
}

size_t			ft_dclst_getcount(t_dc_lst *dclst)
{
	t_dc_lst	*tmp;
	size_t		link_count;

	link_count = 0;
	tmp = dclst->head;
	while (tmp)
	{
		link_count++;
		tmp = tmp->next;
	}
	return (link_count);
}

t_dc_lst		*ft_dclst_create(t_dc_lst_link *lst_to_insert)
{
	t_dc_lst	*new_dclst;

	if (!(new_dclst = ft_memalloc(sizeof(t_dc_lst))))
		return (NULL);
	if (!lst_to_insert)
		return (new_dclst);
	new_dclst = (t_dc_lst){ft_dclst_gethead(lst_to_insert)
						, ft_dclst_gettail(lst_to_insert)
						, ft_dclst_getcount(new_dclst)};
	return (new_dclst);
}
