/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flatten_charr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:31:13 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flatten_charr(char **a)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (a[i])
		len += ft_strlen(a[i++]) + 1;
	len += 1;
	s = malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (a[i])
	{
		ft_strcpy(&s[len], a[i]);
		len += ft_strlen(a[i]);
		s[len++] = '\n';
		i += 1;
	}
	s[len] = '\0';
	return (s);
}
