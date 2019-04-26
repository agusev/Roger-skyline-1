/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:44:46 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		c;
	int		l;

	l = ft_strlen(needle);
	if (l == 0)
		return ((char *)haystack);
	i = 0;
	c = 0;
	while (i < len && haystack[i])
	{
		if (c < l && haystack[i] == needle[c])
		{
			c += 1;
			if (c == l)
				return ((char *)(haystack + i - c + 1));
		}
		else
		{
			i -= c;
			c = 0;
		}
		i += 1;
	}
	return (NULL);
}
