/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusev <agusev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:25:58 by agusev            #+#    #+#             */
/*   Updated: 2019/04/25 22:22:35 by agusev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SWP(X, Y, S) {char *_a=(char *)(X),*_b=(char *)(Y),_t; int _s=(S);SWPW}
# define SWPW while(_s-- > 0){_t=*_a;*_a=*_b;*_b=_t;_a++;_b++;}
# define SWPINT(X, Y)	SWP(X, Y, sizeof(int))
# define SWPLNG(X, Y)	SWP(X, Y, sizeof(long))
# define SWPLLNG(X, Y)	SWP(X, Y, sizeof(long long))
# define SWPDBL(X, Y)	SWP(X, Y, sizeof(double))
# define SWPLDBL(X, Y)	SWP(X, Y, sizeof(long double))
# define SWPCHR(X, Y)	SWP(X, Y, sizeof(char))
# define SWPSTR(X, Y)	SWP(X, Y, sizeof(char *))

# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

#endif
