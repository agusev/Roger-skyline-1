/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:17:47 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

extern int	vaprintf(char **s, const char *format, va_list av);

int			ft_printf(const char *format, ...);
int			ft_printf_fd(int fd, const char *format, ...);
int			ft_sprintf(char **s, const char *format, ...);
char		*ft_ssprintf(const char *format, ...);

#endif
