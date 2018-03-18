/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 04:56:23 by jbulant           #+#    #+#             */
/*   Updated: 2017/12/07 09:19:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void **))
{
	t_list *next;

	while (*alst)
	{
		next = (*alst)->next;
		del(&((*alst)->content));
		free(*alst);
		*alst = next;
	}
}
