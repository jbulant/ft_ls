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

void		read_lst(t_list **lst, void (*del)(void**))
{
	t_list		*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->content)
		{
			ft_putendl(((t_file*)(*lst)->content)->elem->d_name);
			if (del)
				del((void**)&(*lst)->content);
		}
		tmp = *lst;
		*lst = (*lst)->next;
		if (del)
			del((void**)&tmp);
	}
}

void		ft_sortlst(t_list **lst, t_ls_sort sort_mode)
{
	t_list	*previous;
	t_list	*current;
	// t_list	*tmp;
	// int		cmp;

	if (!lst || !*lst || !(*lst)->content)
		return ;
	current = *lst;
	previous = NULL;
	if (sort_mode == NAME)
	{
		while(current->next)
		{
			if (ft_strcmp(((t_file*)current->content)->elem->d_name
				, ((t_file*)current->next->content)->elem->d_name) > 0)
			{
				if (previous)
				{
					previous->next = current->next;
					current->next = current->next->next;
					previous->next->next = current;
				}
				else
				{
					//previous == a
					previous = current->next;
					// (c == current) c->next = (a)->next
					current->next = previous->next;
					// c->b->d
					previous->next = current;
					*lst = previous;
					previous = NULL;
				}
				current = *lst;
				continue ;
			}
			previous = current;
			current = current->next;
			// printf("%s\n", ((t_file*)current->next->content)->elem->d_name);
		}
	}
}
/*

	c / a / b / d
	c<->a / b / d
	a / c / b / d
	a->next = c
	c->next = b
	head = a
	c = current = *lst
	a = c->next = *lst->next
	b = a->next

	current->next = current->next->next
	c->next = a->next
	(*lst)->next = current
	a->next = c
*/
/*
	a / c / b / d
	a / b<->c / d

	a->next = b
	b->next = c
	c->next = d
*/

#define FILE_TEST "*"

void		print_test(t_env *env)
{
	t_list			*lst;
	DIR				*dir;
	t_file			file;

	lst = NULL;
	if (env->file_list)
		return ;
	if (!(dir = opendir(THIS_DIR)))
	{
		ft_putstr("-ft_ls: invalid option -- '"FILE_TEST"': ");
		ft_putendl(strerror(errno));
		perror("opendir");
		exit(1);
	}
	while ((file.elem = readdir(dir)))
	{
		lstat(file.elem->d_name, &file.info);
		if ((file.elem->d_name[0] == '.' && !(env->filters & ALL_FILES))
			|| (!(file.info.st_mode & S_IFDIR) && env->filters & DIRECTORY))
			continue ;
		ft_lstadd(&lst, ft_lstnew(&file, sizeof(t_file)));
		ft_sortlst(&lst, env->sort_mode);
	}
	read_lst(&lst, ft_memdel);
	closedir(dir);
	(void)env;
}

int			main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	if (ac != 1)
		parse_arguments(&env, av + 1);
	printf("mod: %#08x\n", env.sort_mode);
	print_test(&env);
	ft_lstdel(&env.file_list, ft_memdel);
	return (0);
}
