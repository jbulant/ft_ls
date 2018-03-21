/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 22:05:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:39:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_adv_lst.h"

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
	t_dc_lst_link	*tmp;
	size_t			link_count;

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
	*new_dclst = (t_dc_lst){ft_dclst_gethead(lst_to_insert)
						, ft_dclst_gettail(lst_to_insert)
						, ft_dclst_getcount(new_dclst)};
	return (new_dclst);
}
