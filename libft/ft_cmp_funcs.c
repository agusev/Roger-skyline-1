/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:34:39 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fn_cmp_int(const void *a, const void *b)
{
	int		aa;
	int		bb;

	aa = *((int *)a);
	bb = *((int *)b);
	return ((aa > bb) - (aa < bb));
}

int		fn_cmp_long(const void *a, const void *b)
{
	long	aa;
	long	bb;

	aa = *((long *)a);
	bb = *((long *)b);
	return ((aa > bb) - (aa < bb));
}

int		fn_cmp_double(const void *a, const void *b)
{
	double	aa;
	double	bb;

	aa = *((double *)a);
	bb = *((double *)b);
	return ((aa > bb) - (aa < bb));
}

int		fn_cmp_str(const void *a, const void *b)
{
	char	*aa;
	char	*bb;

	aa = (char *)a;
	bb = (char *)b;
	return (ft_strcmp(aa, bb));
}
