# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agusev <agusev@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:54:51 by agusev            #+#    #+#              #
#    Updated: 2019/04/26 00:13:46 by agusev           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:		$(NAME) all clean fclean re

NAME	:=	libftprintf.a
SOURCES	:=	./*.c \
			\
			./formats/*.c \
			\
			./helpers/*.c

OBJECTS	:=	$(SOURCES:.c=.o)
OBJECTS	:=	$(subst formats/,,$(OBJECTS))
OBJECTS	:=	$(subst helpers/,,$(OBJECTS))

all:		$(NAME)

$(NAME):
			gcc -Wall -Wextra -Werror -I. -c $(SOURCES)
			ar rcs $(NAME) $(OBJECTS)

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all

reclean:	re; make clean
