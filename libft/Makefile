# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:54:51 by agusev            #+#    #+#              #
#    Updated: 2019/04/26 00:12:28 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	./*.c

OBJ	=	$(SRCS:.c=.o)

PRINTF	=	ft_printf/*.o


all:		$(NAME)

$(NAME):
			make -C ft_printf/
			gcc -Wall -Wextra -Werror -I. -Ift_printf/ -c $(SRCS)
			ar rcs $(NAME) $(OBJ) $(PRINTF)

clean:
			make -C ft_printf/ clean
			rm -f $(OBJ)

fclean:		clean
			make -C ft_printf/ fclean
			rm -f $(NAME)

re: 		fclean all
			make -C ft_printf/ re

