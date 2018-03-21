/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adv_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 22:06:41 by jbulant           #+#    #+#             */
/*   Updated: 2018/03/17 03:37:15 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADV_LST_H
# define FT_ADV_LST_H

# include "libft.h"

# define LTYPE_(x)		sizeof(x)
# define LTYPE_CHAR		sizeof(char)
# define LTYPE_SHORT	sizeof(short)
# define LTYPE_INT		sizeof(int)
# define LTYPE_DOUBLE	sizeof(double)

# define WARNING_STR				"/!\\ WARNING /!\\"
# define DCLST_WARNING1				WARNING_STR " a dclst_link has been lost\n"
# define DCLST_WARNING				DCLST_WARNING1 "link inserted had "
# define DCLST_WARNING_PREVIOUS		DCLST_WARNING "a previous link."
# define DCLST_WARNING_NEXT			DCLST_WARNING "a next link."

typedef struct	s_dc_lst_link
{
	struct s_dc_lst_link	*previous;
	struct s_dc_lst_link	*next;
	size_t					ltype;
	size_t					content_cnt;
	size_t					content_size;
	t_byte					content[0];
}				t_dc_lst_link;

typedef struct	s_dc_lst
{
	t_dc_lst_link	*head;
	t_dc_lst_link	*tail;
	size_t			link_count;
}				t_dc_lst;

t_dc_lst		*ft_dclst_create(t_dc_lst_link *lst_to_insert);
t_dc_lst_link	*ft_dclst_newlink(size_t ltype, size_t content_cnt);
t_dc_lst_link	*ft_dclst_jumpat(t_dc_lst *dclst, size_t jmp);
void			ft_dclst_insert_at(t_dc_lst *mainlst, t_dc_lst *to_add, size_t jmp);
void			ft_dclst_insertlink_at(t_dc_lst *mainlst, t_dc_lst_link *to_add, size_t jmp);
void			ft_dclst_push_front(t_dc_lst *dclst, t_dc_lst *to_add);
void			ft_dclst_push_back(t_dc_lst *dclst, t_dc_lst *to_add);
void			ft_dclst_pushlink_front(t_dc_lst *dclst, t_dc_lst_link *to_add);
void			ft_dclst_pushlink_back(t_dc_lst *dclst, t_dc_lst_link *to_add);
t_dc_lst		*ft_dclst_merge(t_dc_lst *mainlst, t_dc_lst *to_insert);

#endif
