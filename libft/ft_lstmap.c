/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 08:18:43 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:43 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*el;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = (*f)(lst);
	el = new;
	while (lst->next)
	{
		lst = lst->next;
		el->next = (*f)(lst);
		el = el->next;
	}
	return (new);
}
