/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 08:59:22 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*b;
	size_t			l;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	b = malloc(sizeof(char) * (l + 1));
	if (b != NULL)
	{
		while (s[i])
		{
			b[i] = (*f)(i, s[i]);
			i += 1;
		}
		b[l] = '\0';
	}
	return (b);
}
