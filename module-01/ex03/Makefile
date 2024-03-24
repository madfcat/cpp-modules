# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 22:41:19 by vshchuki          #+#    #+#              #
#    Updated: 2024/03/24 03:58:58 by vshchuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++17

NAME = violence

SRCS = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp
	
HEADERS = HumanA.hpp \
	HumanB.hpp \
	Weapon.hpp

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