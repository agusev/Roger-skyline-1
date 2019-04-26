/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:30:19 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 23:23:18 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern size_t	g_flags;

/* 
S_ISLNK(mode) 		Return non-zero if the mode is from a symbolic link.
S_ISSOCK(mode)		Return non-zero if the mode is from a socket.

S_IXUSR			Execute (for ordinary files) or search (for directories)
				permission bit for the owner of the file.
S_IXGRP			Execute or search permission bit for the group owner of the file.
S_IXOTH			Execute or search permission bit for other users.
S_ISUID			This is the set-user-ID on execute bit.
S_ISGID			This is the set-group-ID on execute bit.
S_IFDI			This is the file type constant of a directory file.
*/

static void		get_color_string(char **s, t_file *file)
{
	*s = "%s";
	if (S_ISLNK(file->st->st_mode))
		*s = "%~fmagenta~%s%~-a~";
	else if (S_ISSOCK(file->st->st_mode))
		*s = "%~fgreen~%s%~-a~";
	else if (file->st->st_mode & S_ISUID)
		*s = "%~fblack;bred~%s%~-a~";
	else if (file->st->st_mode & S_ISGID)
		*s = "%~fblack;bcyan~%s%~-a~";
	else if (file->st->st_mode & S_IFDIR)
		*s = "%~s;flcyan~%s%~-a~";
	else if ((file->st->st_mode & S_IXUSR) || (file->st->st_mode & S_IXGRP)
		|| (file->st->st_mode & S_IXOTH))
		*s = "%~fred~%s%~-a~";
}

static char		*readlnk(const char *filename)
{
	int		size;
	int		n;
	char	*buf;

	size = 2000;
	buf = malloc(size);
	if (buf)
	{
		n = readlink(filename, buf, size - 1);
		if (n > -1)
			buf[n] = '\0';
	}
	return (buf);
}

void			colorize(t_file file)
{
	char	s[2000];
	char	*ss;

	ss = s;
	get_color_string(&ss, &file);
	ft_printf((g_flags & 128) ? ss : "%s", file.name);
	if ((g_flags & 4) && S_ISLNK(file.st->st_mode))
	{
		ft_printf(" -> ");
		ft_memset(s, 0, 2000);
		ft_strcpy(s, file.path);
		s[ft_strlen(file.path)] = '/';
		ft_strcpy(s + ft_strlen(file.path) + 1, file.name);
		ss = readlnk(s);
		ft_printf(ft_strlen(ss) == 0 ? "" : ss);
		ft_strdel(&ss);
	}
	ft_printf("\n");
}
