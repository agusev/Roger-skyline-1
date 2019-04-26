/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 08:59:22 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*b;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (ft_strnew(0));
		else
			return ((char *)(s1 == NULL ? ft_strdup(s2) : ft_strdup(s1)));
	}
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	b = malloc(sizeof(char) * (l1 + l2 + 1));
	if (b != NULL)
	{
		ft_strcpy(b, s1);
		ft_strcpy(b + l1, s2);
		b[l1 + l2] = '\0';
	}
	return (b);
}
