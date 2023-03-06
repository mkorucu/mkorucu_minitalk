# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkorucu <mkorucu@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 15:53:26 by mkorucu           #+#    #+#              #
#    Updated: 2022/08/29 18:55:10 by mkorucu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= sourcesminitalk.a
SRCS	= ft_printf.c ft_others.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar rcs

all		: ${NAME}

$(NAME)	: ${OBJS} 
	${AR} ${NAME} ${OBJS}

clean	: 
		${RM} ${OBJS}

fclean : 
	${RM} ${NAME} ${OBJS}

re : fclean all

.PHONY:		all clean fclean re
