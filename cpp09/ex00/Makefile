# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gorg <gorg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 23:25:13 by gorg              #+#    #+#              #
#    Updated: 2024/12/08 18:15:36 by gorg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++20 -g

###
SRCS_DIR = 

###
FILES = main.cpp BitcoinExchange.cpp

###
SRCS = $(addprefix $(SRCS_DIR),$(FILES))
OBJS = $(SRCS:.cpp=.o)

###
all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

###

.PHONY: all clean fclean re
