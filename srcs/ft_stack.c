/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:46:34 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/11 05:07:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

size_t	ft_stack_totalsize(t_stack *stack)
{
	size_t height;

	height = stack->blocks_count - 1;
	return (height * stack->chunk_size + stack->blocks[height]->size);

}

int		ft_stack_realloc(t_stack *stack)
{
	t_stack_block	**new;
	int				i;

	stack->max_height += INITIAL_STACK_SIZE;
	if (!(new = ft_memalloc(sizeof(t_stack_block*) * stack->max_height)))
		return (FT_STACK_ERROR);
	i = -1;
	while (++i < (int)stack->blocks_count)
		new[i] = stack->blocks[i];
	free(stack->blocks);
	stack->blocks = new;
	return (FT_STACK_SUCCESS);
}

int  	ft_stack_newblock(t_stack *stack)
{
	t_stack_block	*new;
	size_t			sblock_size;

	sblock_size =  sizeof(void*) * stack->chunk_size;
	if (!(new = ft_memalloc(sizeof(t_stack_block)))
		|| !(new->content = ft_memalloc(sblock_size)))
		return (FT_STACK_ERROR);
	if (stack->blocks_count >= stack->max_height
		&& !ft_stack_realloc(stack))
		return (FT_STACK_ERROR);
	stack->blocks[stack->blocks_count++] = new;
	return (FT_STACK_SUCCESS);
}

int 	ft_stack_init(t_stack *stack, size_t chunk_size)
{
	if (!stack)
		return (FT_STACK_ERROR);
	ft_bzero(stack, sizeof(t_stack));
	stack->blocks = ft_memalloc(sizeof(t_stack_block*) * INITIAL_STACK_SIZE);
	if (!stack->blocks)
		return (FT_STACK_ERROR);
	stack->max_height = INITIAL_STACK_SIZE;
	stack->chunk_size = chunk_size;
	return (ft_stack_newblock(stack));
}

int		ft_stack_add_content(t_stack *stack, void *content)
{
	size_t		height;

	if ((!stack->blocks_count
		|| stack->blocks[stack->blocks_count - 1]->size == stack->chunk_size)
		&& !ft_stack_newblock(stack))
		return (FT_STACK_ERROR);
	height = stack->blocks_count - 1;
	stack->blocks[height]->content[stack->blocks[height]->size++] = content;
	return (1);
}

void	*ft_stack_get_content(t_stack *stack)
{
	t_stack_block	*block;
	void			*content;

	if (!stack->blocks_count)
		return (FT_STACK_EMPTY);
	block = stack->blocks[stack->blocks_count - 1];
	content = block->content[--block->size];
	if (!block->size)
	{
		free(block->content);
		free(block);
		stack->blocks_count--;
	}
	return (content);
}

int		ft_stack_merge_sort(t_stack *stack, int (*cmp)(void*, void*));

#include <unistd.h>
#include <stdio.h>
int				test_stack()
{
	char b[1];
	t_stack stack;

	read(0, b, 1);
	if (!(ft_stack_init(&stack, 1)))
		printf("ft_stack_init : [FAILED]\n");
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 52; i++) {
			char c[2] = {'a' + (i % 26) - (32 * (i / 26)), '\0'};
			if (!ft_stack_add_content(&stack, (void*)ft_strdup(c)))
				printf("ft_stack_add_content : [FAILED]\n");
			printf("added: %s\n", c);
		}
		printf("stack HEIGHT: %zu\n", stack.blocks_count);
		while (stack.blocks_count > (size_t)26 * (1 - j)) {
			char *content;
			content = (char*)ft_stack_get_content(&stack);
			printf("%s\n", content);
			free(content);
		}
	}
	while(1);
	return (0);
}
