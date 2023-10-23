# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 10:46:17 by orakib            #+#    #+#              #
#    Updated: 2023/10/23 15:20:37 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

SRC = main.cpp RPN.cpp

HEADER = RPN.hpp

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re