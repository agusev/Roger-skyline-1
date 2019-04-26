/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolvers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:26:49 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVERS_H
# define RESOLVERS_H

# define RCOUNT 18

typedef struct	s_resolve
{
	char		conversion;
	int			type;
}				t_resolve;

t_resolve		g_resolvers[RCOUNT] = {
	{'%', 1},
	{'s', 2},
	{'c', 3},
	{'p', 4},
	{'d', 5},
	{'i', 5},
	{'o', 5},
	{'u', 5},
	{'X', 5},
	{'x', 5},
	{'b', 5},
	{'f', 6},
	{'~', 7},
	{'r', 8},
	{'R', 8},
	{'D', 5},
	{'O', 5},
	{'U', 5}
};

#endif
