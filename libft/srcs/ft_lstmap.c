/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 05:36:51 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/12 03:23:21 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *beginlist;
	t_list *current;

	current = f(lst);
	beginlist = current;
	while ((lst = lst->next))
	{
		current->next = f(lst);
		current = current->next;
	}
	return (beginlist);
}
