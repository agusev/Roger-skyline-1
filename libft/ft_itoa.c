/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:12:53 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	r_itoa(long nb, char *s, int *index)
{
	if (nb < 0)
	{
		s[(*index)++] = '-';
		r_itoa(-nb, s, index);
	}
	else if (nb > 9)
	{
		r_itoa(nb / 10, s, index);
		r_itoa(nb % 10, s, index);
	}
	else
	{
		s[(*index)++] = nb + '0';
	}
	s[*index] = '\0';
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	n2;

	i = 0;
	n2 = n;
	if (n2 < 0)
	{
		n2 = -n2;
		i += 1;
	}
	while (n2 >= 10)
	{
		n2 /= 10;
		i += 1;
	}
	s = ft_strnew(i + 1);
	i = 0;
	if (s != NULL)
		r_itoa(n, s, &i);
	return (s);
}
