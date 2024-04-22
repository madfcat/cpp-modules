# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 02:55:10 by vshchuki          #+#    #+#              #
#    Updated: 2024/03/28 00:49:01 by vshchuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++17

NAME = fixed

SRCS = main.cpp \
	Fixed.cpp \
	Point.cpp
	
HEADERS = Fixed.hpp \
	Point.hpp
	 
OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
CLASS_HEADERS = $(CLASS_SRCS:.cpp=.hpp)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) $(CLASS_HEADERS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp %.hpp | $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re