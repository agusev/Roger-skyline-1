/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:28:27 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_qsort.h"

static void	finish_pass(void *a, t_hilo *s, t_hilo *b,
	int f(const void *, const void *))
{
	while (s->h > b->l)
		if (f(INCPN(a, s->l, s->h), INCPN(a, s->l, s->h - 1)) < 0)
		{
			SWP(INCPN(a, s->l, s->h - 1), INCPN(a, s->l, s->h--), s->l);
		}
		else
			SWP(INCPN(a, s->l, s->h - 1), INCPN(a, s->l, b->l++), s->l);
	while (s->h < b->h)
		if (f(INCPN(a, s->l, s->h), INCPN(a, s->l, s->h + 1)) > 0)
		{
			SWP(INCPN(a, s->l, s->h + 1), INCPN(a, s->l, s->h++), s->l);
		}
		else
			SWP(INCPN(a, s->l, s->h + 1), INCPN(a, s->l, b->h--), s->l);
}

void		ft_qsort(void *a, size_t cnt, size_t sz,
	int f(const void *, const void *))
{
	size_t	med;
	t_hilo	b;
	t_hilo	fl;
	t_hilo	sizes;

	if (cnt < 2)
		return ;
	med = cnt >> 1;
	HILO(b, cnt - 1, 0);
	HILO(fl, 1, 1);
	while (b.l < med && b.h > med)
	{
		b.l += (fl.l = (f(INCPN(a, sz, b.l), INCPN(a, sz, med)) < 0) && fl.l);
		b.h -= (fl.h = (f(INCPN(a, sz, b.h), INCPN(a, sz, med)) > 0) && fl.h);
		if (!fl.l && !fl.h)
		{
			SWP(INCPN(a, sz, b.l++), INCPN(a, sz, b.h--), sz);
			HILO(fl, 1, 1);
		}
	}
	HILO(sizes, med, sz);
	finish_pass(a, &sizes, &b, f);
	med = sizes.h;
	ft_qsort(a, med, sz, f);
	ft_qsort(INCPN(a, sz, med + 1), cnt - med - 1, sz, f);
}
