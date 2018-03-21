/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_newlink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 03:32:09 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:32:28 by jbulant          ###   ########.fr       */
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
