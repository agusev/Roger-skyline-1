/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:31:45 by agusev            #+#    #+#             */
/*   Updated: 2019/04/26 00:10:12 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			g_exit_value = 0;
int			g_file_count = 0;
t_file		*g_root = NULL;
t_dir		*g_dir = NULL;

static void	ls_dir(DIR *dirp, size_t f, char *path, t_file **node)
{
	struct dirent	*ep;// format of directory entries
	char			*p;
	struct stat		st;//  stat - get file status

	while ((ep = readdir(dirp)))
	{
		g_file_count++;
		p = ft_strjoin(path, "/");
		ft_strsetdel(&p, ft_strjoin(p, ep->d_name));
		lstat(p, &st);
		(*node)->next = create_node(*node, ep->d_name, path, &st);
		*node = (*node)->next;
		if ((st.st_mode & S_IFDIR) && (f & 2) &&
			!(ft_strcmp(ep->d_name, ".") == 0 ||
			ft_strcmp(ep->d_name, "..") == 0))
			process_dir(p, f, node);
		ft_strdel(&p);
	}
}

t_file		*process_dir(char *name, size_t f, t_file **root)
{
	DIR				*dirp;
	struct stat		st;
	int				res;

	if ((res = lstat(name == NULL ? "." : name, &st)) != 0)
		file_error(name);
	else if (!(st.st_mode & S_IFDIR))
	{
		create_node(*root, name, ft_strdup(""), &st);
		*root = (*root)->next;
		g_file_count++;
	}
	else
	{
		dirp = opendir(name == NULL ? "." : name);
		if (dirp != NULL)
		{
			ls_dir(dirp, f, name == NULL ? "." : name, root);
			if (closedir(dirp) != 0)
				file_error(name == NULL ? "." : name);
		}
		else
			file_error(name == NULL ? "." : name);
	}
	return (*root);
}

int			main(int ac, char **av)
{
	int			count;
	int			i;
	size_t		f;
	t_file		*node;

	g_root = create_node(NULL, NULL, NULL, NULL);
	node = g_root;
	count = ac - 1;
	f = 0;
	if (count != 0)
		f = check_params(&count, av + 1);
	if (count == 0)
		process_dir(NULL, f, &node);
	else
	{
		i = -1;
		while (++i < count)
			process_dir(av[ac - count + i], f, &node);
	}
	print_data(f, count);
	clear_list(g_root);
	clear_dir(g_dir);
	return (g_exit_value);
}
