# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 11:27:05 by agusev            #+#    #+#              #
#    Updated: 2019/04/25 22:32:08 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls
SOURCES	=	./*.c

all:		$(NAME)

$(NAME):
			make -C libft/
			gcc -g -Wall -Wextra -Werror -o $(NAME) -Llibft -lft $(SOURCES)

clean:
			make -C libft/ clean

fclean:		clean
			make -C libft/ fclean
			rm -f $(NAME)

re: 		fclean all
			make -C libft/ re