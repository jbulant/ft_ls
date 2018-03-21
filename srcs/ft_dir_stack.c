/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 21:40:07 by jerome            #+#    #+#             */
/*   Updated: 2018/03/20 22:34:26 by jerome           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"



struct dirent	*take_file(t_dir_stack *stack)
{
	if (!stack || !stack->size)
		return (NULL);
	return (stack->files[--stack->size]);
}

t_dir_stack		*add_file_to(t_dir_stack *stack, struct dirent *file)
{
	if (stack->size == MAX_DIR_STACK
		&& (stack = add_new_stack(&stack)))
		return (NULL);
	stack->files[stack->size++] = file;
	return (stack); 
}

t_dir_stack		*add_new_stack(t_dir_stack **main_stack)
{
	t_dir_stack		*new_stack;
	t_dir_stack		*stack;

	stack = *main_stack;
	while (stack && stack->next)
		stack = stack->next;
	if (!(new_stack = ft_memalloc(sizeof(t_dir_stack))))
		return (NULL);
	new_stack->deleteme = TRUE;
	if (!stack)
		return ((*main_stack = new_stack));
	return ((stack->next = new_stack));
}