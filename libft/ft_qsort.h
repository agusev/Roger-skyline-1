/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:45:11 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QSORT_H
# define FT_QSORT_H

# include <stdlib.h>

# define HILO(hilo, X, Y)	hilo.h=(X);hilo.l=(Y)
# define INCP(X, S)			(((char *)X) + (S))
# define INCPN(X, S, N)		(((char *)X) + (S) * (N))

typedef struct	s_hilo
{
	size_t		h;
	size_t		l;
}				t_hilo;

#endif
