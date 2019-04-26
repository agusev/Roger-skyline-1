/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatten_tlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:31:13 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lst_content_len(t_list *el)
{
	size_t	len;

	len = 0;
	while (el)
	{
		len += el->content_size;
		el = el->next;
	}
	len += 1;
	return (len);
}

char			*ft_flatten_tlist(t_list const *list)
{
	size_t	len;
	char	*s;
	t_list	*el;

	if (list == NULL)
		return (NULL);
	len = lst_content_len((t_list *)list);
	s = malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	len = 0;
	el = (t_list *)list;
	while (el)
	{
		ft_strcpy(&s[len], el->content);
		len += el->content_size;
		s[len - 1] = '\n';
		el = el->next;
	}
	s[len] = '\0';
	return (s);
}
