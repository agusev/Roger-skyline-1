/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 17:08:43 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:05:44 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	r_itoa(long nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		r_itoa(-nb, fd);
	}
	else if (nb > 9)
	{
		r_itoa(nb / 10, fd);
		r_itoa(nb % 10, fd);
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	r_itoa(n, fd);
}
