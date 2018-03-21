/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:18:36 by jbulant           #+#    #+#             */
/*   Updated: 2017/11/11 20:47:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*newlst;

	if (!(newlst = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL && (newlst->content = ft_memalloc(content_size)))
		newlst->content = ft_memcpy(newlst->content, content, content_size);
	else
		newlst->content = NULL;
	newlst->content_size = (newlst->content != NULL) ? content_size : 0;
	newlst->next = NULL;
	return (newlst);
}
