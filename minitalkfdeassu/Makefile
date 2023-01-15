# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-assu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 13:40:42 by fde-assu          #+#    #+#              #
#    Updated: 2022/11/17 13:40:50 by fde-assu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER	 	= server.c

OBJSSERVER  = $(SERVER:.c=.o)

CLIENT		= client.c

OBJSCLIENT  = $(CLIENT:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -f

NAME		= minitalk

$(NAME):	server client

all:		$(NAME)

server: 	server.o
			$(CC) $(CFLAGS) server.o -o server

client: 	client.o
			$(CC) $(CFLAGS) client.o -o client

clean:
		$(RM) $(OBJSSERVER) $(OBJSCLIENT)

fclean:		clean
			$(RM) server client

re:			fclean all

.PHONY:		all clean fclean re 
