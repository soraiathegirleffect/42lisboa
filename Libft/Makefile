# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: somartin <somartin@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 15:59:36 by somartin          #+#    #+#              #
#    Updated: 2022/11/20 19:19:23 by somartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_memset.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memchr.c\
					ft_calloc.c ft_strdup.c ft_isalnum.c ft_isprint.c \
					ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
					ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_bzero.c ft_isascii.c \
					ft_strlen.c  ft_strrchr.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
					ft_isdigit.c ft_tolower.c ft_toupper.c \
					ft_substr.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_strtrim.c \
					
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
					
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJS)
				ar rcs $(NAME) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
