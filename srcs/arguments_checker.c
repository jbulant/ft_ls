/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerome <jerome@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:14:59 by jerome            #+#    #+#             */
/*   Updated: 2018/04/13 20:33:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		show_help(void)
{
	ft_putendl(HELP);
	exit(0);
}

static void		send_l_opt_error(t_const_buffer *arg, int match_count
								, int indexes, const char *l_opt[LONG_OPT_MAX])
{
	int			i;

	if (arg->size <= ft_strlen(LONG_OPT_HELP)
		&& ft_strnequ(arg->buffer, LONG_OPT_HELP, arg->size))
		return (show_help());
	if (!indexes)
		ft_error(UNRECOGNIZED_L_OPTION | SHOW_HELP_CMD_FOR_INFO | FATAL_ERROR
				, arg->buffer);
	ft_error(AMBIGUOUS_L_OPTION, arg->buffer);
	i = -1;
	ft_putstr("                                  ");
	while (++i != LONG_OPT_MAX && match_count)
	{
		if (indexes & (1 << i))
		{
			ft_putstr_fd((char*)l_opt[i], 2);
			ft_putstr_fd(--match_count ? "; " : "\n", 2);
		}
	}
	ft_error(SHOW_HELP_CMD_FOR_INFO | FATAL_ERROR, NULL);
}

void			check_long_option(t_env *env, t_const_buffer *arg
								, t_bool *check)
{
	static const char		*l_opt[LONG_OPT_MAX] = {LONG_OPTS};
	int						match_count;
	int						matched_indexes;
	int						i;

	if (ft_strequ(arg->buffer, "--"))
		return ((void)(*check = FALSE));

	match_count = 0;
	matched_indexes = 0;
	i = -1;
	while (++i != LONG_OPT_MAX)
	{
		if (ft_strlen(l_opt[i]) > arg->size)
		{
			if (ft_strnequ(arg->buffer, l_opt[i], arg->size))
			{
				match_count++;
				matched_indexes |= 1 << i;
			}
		}
		else if (ft_strequ(arg->buffer, l_opt[i]))
		{
			match_count++;
			matched_indexes |= 1 << i;
			break ;
		}
	}
	if (match_count != 1)
		send_l_opt_error(arg, match_count, matched_indexes, l_opt);
	else if (matched_indexes & REVERSE)
		env->sort_mode |= matched_indexes & REVERSE;
	else
		env->filters |= matched_indexes;
}

void			check_option(t_env *env, t_const_buffer *arg, t_bool *check)
{
	static const char		opt_letters[] = OPT_LETTERS;
	int						i;

	if (arg->buffer[1] == '-')
		return (check_long_option(env, arg, check));

	while(*(++arg->buffer))
	{
		i = -1;
		while (++i < OPT_MAX && *arg->buffer != opt_letters[i])
			;
		if (i == OPT_MAX)
			ft_error(INVALID_S_OPTION | SHOW_HELP_CMD_FOR_INFO | FATAL_ERROR
					, arg->buffer);
		if (i < OPT_FIRST_SORT_LETTER && !(env->filters & (i << i)))
			env->filters |= (1 << i);
		else
			env->sort_mode |= (1 << (i - OPT_FIRST_SORT_LETTER));
	}
}

int				add_self_to_stack(t_stack *stack)
{
	t_file	 *self;

	if (!(self = ft_memalloc(sizeof(t_file))))
		return (0);
	*(short*)self->name = *(short*)(".");
 	// *(short*)self->name = *(short*)("/");
	// ft_strcpy(self->name, "/Users/jbulant/");
	self->nsize = ft_strlen(self->name);
	ft_stack_add_content(stack, self);
	return (1);
}

void			parse_arguments(t_env *env, char **args)
{
	t_const_buffer		current_arg;
	t_bool				check;
	t_list				*new_file;

	check = TRUE;
	new_file = NULL;
	while(*args)
	{
		current_arg.buffer = *args;
		current_arg.size = ft_strlen(*args);
		if (check && *current_arg.buffer == '-' && current_arg.size >= 2)
			check_option(env, &current_arg, &check);
		else
		{
			new_file = ft_lstnew(current_arg.buffer, current_arg.size + 1);
			if (env->file_list)
				new_file->next = env->file_list;
			env->file_list = new_file;
		}
		args++;
	}
	if (!env->file_list)
		add_self_to_stack(&env->dir_stack);
	init_env_functions(env);
}
