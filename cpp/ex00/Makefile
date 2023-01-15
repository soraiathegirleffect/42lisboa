# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efreire- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 22:00:23 by efreire-          #+#    #+#              #
#    Updated: 2022/12/17 22:00:25 by efreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= TypeConverter.cpp main.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -std=c++98

NAME			= convert

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:
				@make fclean
				@clear
				@make
				./$(NAME) 42
				./$(NAME) 65
				./$(NAME) -42
				./$(NAME) 0
				./$(NAME) 0.0
				./$(NAME) 0.0f
				./$(NAME) .0
				./$(NAME) .0f
				./$(NAME) 2147483647
				./$(NAME) -2147483648
				./$(NAME) 2147483648
				./$(NAME) -2147483649
				./$(NAME) nan
				./$(NAME) inff
				./$(NAME) +inff
				./$(NAME) inf

.PHONY:			all $(NAME) clean fclean re test
