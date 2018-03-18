#include <stdio.h>
#include "ft_ls.h"
#include <limits.h>
#include <locale.h>

static void		init_env(t_env *env)
{
	env->file_list = NULL;
	env->sort_mode = NAME;
	env->filters = NO_FILTER;
}

int			main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	if (ac != 1)
		parse_arguments(&env, av + 1);
	ft_lstdel(&env.file_list, ft_memdel);
	return (0);
}
