/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:02:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/10 00:21:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*findmid(t_list *lst)
{
	t_list	*mid;

	if (!lst)
		return (NULL);
	mid = lst;
	while (lst->next && lst->next->next)
	{
		mid = mid->next;
		lst = lst->next->next;
	}
	return (mid);
}

static t_list	*merge(t_list *l1, t_list *l2, int (*cmp)())
{
	t_list	*res;
	int		cmp_ret;

	res = NULL;
	if (!l1)
		return (l2);
	else if (!l2)
		return (l1);
	cmp_ret = cmp(l1->content, l2->content);
	if (cmp_ret <= 0)
	{
		res = l1;
		res->next = merge(l1->next, l2, cmp);
	}
	else
	{
		res = l2;
		res->next = merge(l1, l2->next, cmp);
	}
	return (res);
}

void			ft_lstsort(t_list **head, int (*cmp)())
{
	t_list	*midlst;
	t_list	*spart;

	if (!(*head) || !(*head)->next)
		return ;
	midlst = findmid(*head);
	spart = midlst->next;
	midlst->next = NULL;
	ft_lstsort(head, cmp);
	ft_lstsort(&spart, cmp);
	*head = merge(*head, spart, cmp);
}
