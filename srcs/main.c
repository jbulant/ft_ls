#include <stdio.h>
#include "ft_ls.h"
#include <limits.h>
#include <locale.h>

int file_cmp(t_file *v1, t_file *v2)
{
	t_file *f1, *f2;
	f1 = (t_file*)v1;
	f2 = (t_file*)v2;
	return (ft_strcmp(f1->name, f2->name));
}

void printinfo(char *name, struct stat *info) {
	printf("%s :\n", name);
	printf("S_IFDIR: %#o || %#o\n", S_IFDIR, info->st_mode & S_IFDIR);
}

int		f_isdir(t_file *file)
{
	struct stat		info;
	int				lstatret;

	if (file->path->name[file->path->nsize - 1] != '/')
		file->path->name[file->path->nsize++] = '/';
	ft_strcpy(file->path->name + file->path->nsize, file->name);
	if ((lstatret = lstat(file->path->name, &info)) == -1)
		perror("lstat");
	if (lstatret == 0 && info.st_mode & S_IFDIR && ft_strcmp(file->name, ".") && ft_strcmp(file->name, "..")) {
		file->nsize += file->path->nsize;
		ft_strcpy(file->name, file->path->name);
		return (1);
	}
	return (0);
}

int		read_lst(t_file *flst, t_env *env)
{
	if (!flst)
		return (1);
	ft_awstrncatendl(&env->awstr, flst->name, flst->nsize);
	if (flst->next)
		read_lst(flst->next, env);
	if (!f_isdir(flst))
		free(flst);
	else if (!ft_stack_add_content(&env->dir_stack, flst))
		return (0);
	return (1);
}

int			ft_treatdir(t_file *current_dir, t_env *env)
{
  //	t_list			*lst;
	t_file			*flst;
	DIR				*dir;
	struct dirent	*elem;
	t_file			file;

	if (!(dir = opendir(current_dir->name)))
	{
		// printf("-ft_ls: invalid option -- '%s': ", current_dir->name);
		// ft_putendl(strerror(errno));
		// perror("opendir");
		return (0);
	}
	flst = NULL;
	//	lst = NULL;
	file.path = current_dir;
	// if (current_dir->path)
	// 	create_dirname(current_dir, current_dir->path);
	while ((elem = readdir(dir)))
	{
		if (elem->d_name[0] == '.' && !(env->filters & ALL_FILES))
			continue ;
		file.nsize = ft_strlen(elem->d_name);
		ft_strcpy(file.name, elem->d_name);
		flst_add(&flst, flstdup(&file));
		//	ft_lstadd(&lst, ft_lstnew(&file, sizeof(t_file)));
	}
	//	ft_lstsort(&lst, file_cmp);
	read_lst(flst, env);
	closedir(dir);
	free(current_dir);
	return (1);
}

int			loop_recurs(t_env *env)
{
	t_file	*current_dir;

	while(env->dir_stack.blocks_count)
	{
		current_dir = ft_stack_get_content(&env->dir_stack);
		if (ft_strcmp(current_dir->name, "."))
		{
			ft_awstrncat(&env->awstr, current_dir->name
						, ft_strlen(current_dir->name));
			ft_awstrncat(&env->awstr, ":\n", 2);
		}
		ft_treatdir(current_dir, env);
		if (env->dir_stack.blocks_count)
			ft_awstrncat(&env->awstr, "\n", 1);
	}
	return (1);
}

int			loop_norecurs(t_env *env)
{
	(void)env;
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	(void)ac;
	parse_arguments(&env, av + 1);
	// test_stack();
	// print_test(&env);
	// test_awstr();
	(env.filters & RECURSIVE) ? loop_recurs(&env) : loop_norecurs(&env);
	ft_putawstr(&env.awstr);
	// ft_lstdel(&env.file_list, ft_memdel);
	return (0);
}
