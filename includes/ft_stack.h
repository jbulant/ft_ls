/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:22:07 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/09 20:53:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include "libft.h"
# include <stdlib.h>

# define FT_STACK_ERROR			0
# define FT_STACK_SUCCESS		1
# define FT_STACK_EMPTY			0

# define MAX_STACK_BLOCK_SIZE   256
# define INITIAL_STACK_SIZE     10

/*
**		return values for (int(*function)()) :
**			0 == ERROR
**			1 == OK
**
**		can be checked like 'if (ft_stack_add_content(foo)) then SUCCESS'
**
**		ft_stack_init() MUST be called at first before adding content
*/

typedef struct 	s_stack_block
{
  size_t    size;
  void      **content;
}              	t_stack_block;

typedef struct 	s_stack
{
  t_stack_block	**blocks;
  size_t       	blocks_count;
  size_t		max_height;
  size_t		chunk_size;
}              	t_stack;

int 			ft_stack_init(t_stack *stack, size_t chunk_size);
int            	ft_stack_sort(t_stack *stack, int (*cmp)(void*, void*));
int				ft_stack_add_content(t_stack *stack, void *content);
void			*ft_stack_get_content(t_stack *stack);
int			  	ft_stack_newblock();

int				test_stack();

#endif
