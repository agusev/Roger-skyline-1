/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:10:48 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:43 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		count;
	int		i;
	char	**a;

	if (s == NULL || c == '\0')
		return (NULL);
	count = ft_word_count(s, c);
	a = malloc(sizeof(char *) * (count + 1));
	if (a == NULL)
		return (NULL);
	a[count] = 0;
	i = 0;
	while (i < count)
	{
		a[i] = ft_extract_word(s, c, i + 1);
		i += 1;
	}
	return (a);
}
