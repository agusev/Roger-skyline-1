/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 11:18:13 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	prepare(const int fd, char **line)
{
	if (fd < 0)
		return (-1);
	if (line == NULL)
		return (-1);
	*line = ft_strnew(0);
	if (*line == NULL)
		return (-1);
	return (0);
}

static int	init_fpt(t_list **fpt, const int fd)
{
	t_fpt	*d;

	d = (t_fpt *)malloc(sizeof(t_fpt));
	if (d == NULL)
		return (-1);
	d->fd = fd;
	d->buf = ft_strnew(0);
	if (d->buf == NULL)
		return (-1);
	*fpt = ft_lstnew(d, sizeof(t_fpt));
	if (*fpt == NULL)
	{
		free(d->buf);
		free(d);
		return (-1);
	}
	free(d);
	return (1);
}

static int	get_pd(t_list **cpd, t_list *beg, const int fd)
{
	t_list	*el;
	t_fpt	*d;

	el = beg;
	while (1)
	{
		d = (t_fpt *)el->content;
		if (d->fd == fd)
		{
			if (d->buf == NULL)
				return (-1);
			*cpd = el;
			return (1);
		}
		if (el->next != NULL)
			el = el->next;
		else
			break ;
	}
	if (init_fpt(cpd, fd) == 1)
		el->next = *cpd;
	else
		return (-1);
	return (1);
}

static int	finish_read(char **line, char *s, t_fpt *d)
{
	int		i;
	int		l;
	char	*sub;
	char	*buf;

	buf = ft_strjoin(d->buf, s);
	ft_strsetdel(&d->buf, ft_strnew(0));
	i = ft_strchri(buf, '\n');
	if (i == -1)
		ft_strsetdel(line, ft_strjoin(*line, buf));
	else
	{
		if (i != 0)
		{
			sub = ft_strsub(buf, 0, i);
			ft_strsetdel(line, ft_strjoin(*line, sub));
			ft_strdel(&sub);
		}
		l = (int)ft_strlen(buf);
		ft_strsetdel(&d->buf, ft_strsub(buf, i + 1, l - i - 1));
	}
	ft_strclr(s);
	ft_strdel(&buf);
	return (i == -1 ? 0 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*fpt = NULL;
	t_list			*d;
	char			*buf;
	ssize_t			c;
	ssize_t			i;

	if ((prepare(fd, line) == -1) ||
		(i = (fpt == NULL) ? init_fpt(&d, fd) : get_pd(&d, fpt, fd)) < 1)
		return (-1);
	fpt = (fpt == NULL) ? d : fpt;
	buf = ft_strnew(BUFF_SIZE);
	while (1)
	{
		if (ft_strchr(((t_fpt *)(d->content))->buf, '\n') == NULL)
		{
			if ((c = read(fd, buf, BUFF_SIZE)) < 0)
				return (ft_freeret((void **)(&buf), -1));
			else if (c == 0 && ft_strlen(((t_fpt *)(d->content))->buf) == 0)
				return (ft_freeret((void **)(&buf),
					ft_strlen(*line) > 0 ? 1 : 0));
		}
		if (finish_read(line, buf, (t_fpt *)(d->content)) == 1)
			return (ft_freeret((void **)(&buf), 1));
	}
}
