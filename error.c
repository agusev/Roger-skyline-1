/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 22:54:33 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 21:59:46 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern int		g_exit_value;
extern t_file	*g_root;
extern t_dir	*g_dir;

void			error(char *message, int and_exit, int and_free)
{
	ft_printf("%s: %s", NAME, message);
	if (and_free == 1)
		free(message);
	if (and_exit == 1)
	{
		clear_list(g_root);
		clear_dir(g_dir);
		exit(1);
	}
}

void			file_error(char *file_name)
{
	extern int	errno;

	ft_printf("%s: %s: %s\n", NAME, file_name, strerror(errno));
	g_exit_value = 1;
}
