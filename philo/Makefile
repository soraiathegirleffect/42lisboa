# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifreire- <ifreire-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 15:21:04 by ifreire-          #+#    #+#              #
#    Updated: 2023/01/14 20:47:53 by ifreire-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= src/philo.c src/extra_philo.c src/utils_free_printf.c \
				src/utils_libft.c src/utils_parse.c src/utils_time.c \
				src/m_global_running.c src/m_global_threads.c src/init_values.c

OBJ				= $(SRC:.c=.o)

CC				= gcc -Wall -Wextra -Werror

NAME			= philo

%.o: %.c
	$(CC) -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -fsanitize=address -o $(NAME) -lpthread
#valgrind --leak-check=full --show-leak-kinds=all

clean:
				rm -f $(OBJ)

fclean: 		clean
				rm -f $(NAME)

re: 			fclean $(NAME)

.PHONY: all clean fclean re test
