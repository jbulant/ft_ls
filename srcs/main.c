#include <stdio.h>
#include "ft_ls.h"
#include <limits.h>
#include <locale.h>

void		read_lst(t_list **lst, void (*del)(void**))
{
	t_list		*tmp;
	t_file		*file;

	if (!lst)
		return ;
	while (*lst)
	{
		if ((*lst)->content)
		{
			file = ((t_file*)(*lst)->content);
			ft_putendl(file->elem->d_name);
			if (del)
				del((void**)&(*lst)->content);
		}
		tmp = *lst;
		*lst = (*lst)->next;
		if (del)
			del((void**)&tmp);
	}
}

void		ft_sortlst(t_list **lst, t_env *env)
{
	t_list			*previous;
	t_list			*current;
	struct dirent	*f1;
	struct dirent	*f2;

	if (!lst || !*lst || !(*lst)->content || !env)
		return ;
	current = *lst;
	previous = NULL;
	while(current->next)
	{
		f1 = ((t_file*)current->content)->elem;
		if (!current || current->next->content)
			f2 = ((t_file*)current->next->content)->elem;
		else
			f2 = NULL;
		if (!f1 || !f2)
			continue ;
		if (env->sort_cmp_f(f1->d_name, f2->d_name, FALSE))
		{
			if (previous)
			{
				previous->next = current->next;
				current->next = current->next->next;
				previous->next->next = current;
			}
			else
			{
				previous = current->next;
				current->next = previous->next;
				previous->next = current;
				*lst = previous;
				previous = NULL;
			}
			current = *lst;
			continue ;
		}
		previous = current;
		current = current->next;
	}
}

#define FILE_TEST "*"

void		print_test(t_env *env)
{
	t_list			*lst;
	DIR				*dir;
	t_file			file;

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
		ft_sortlst(&lst, env);
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
	// print_test(&env);
	ft_lstdel(&env.file_list, ft_memdel);
	return (0);
}
