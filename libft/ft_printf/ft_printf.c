/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:10:06 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sprintf(char **s, const char *format, ...)
{
	va_list		av;
	int			result;

	va_start(av, format);
	result = vaprintf(s, format, av);
	va_end(av);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	char		*s;
	va_list		av;
	int			result;

	va_start(av, format);
	result = vaprintf(&s, format, av);
	va_end(av);
	write(1, s, result);
	free(s);
	return (result);
}

int		ft_printf_fd(int fd, const char *format, ...)
{
	char		*s;
	va_list		av;
	int			result;

	va_start(av, format);
	result = vaprintf(&s, format, av);
	va_end(av);
	write(fd, s, result);
	free(s);
	return (result);
}

char	*ft_ssprintf(const char *format, ...)
{
	va_list		av;
	char		*s;

	s = NULL;
	va_start(av, format);
	vaprintf(&s, format, av);
	va_end(av);
	return (s);
}
