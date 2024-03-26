# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 21:25:22 by vshchuki          #+#    #+#              #
#    Updated: 2024/03/27 00:22:58 by vshchuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++17

NAME = losersed

SRCS = main.cpp \
	Replacer.cpp

HEADERS = Replacer.hpp

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

CLASS_HEADERS = $(CLASS_SRCS:.cpp=.hpp)

TESTER_NAME = tester
TESTER_SRCS = tester.cpp
TESTER_OBJ_DIR = tester_objs/
TESTER_OBJS = $(addprefix $(TESTER_OBJ_DIR), $(TESTER_SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) $(CLASS_HEADERS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp %.hpp | $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

# Tester
$(TESTER_OBJ_DIR):
	mkdir -p $(TESTER_OBJ_DIR)

$(TESTER_OBJ_DIR)%.o: %.cpp | $(TESTER_OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $< -o $@

$(TESTER_NAME): $(TESTER_OBJ_DIR) $(TESTER_OBJS) $(NAME) 
	$(COMPILER) $(FLAGS) $(TESTER_OBJS) -o $(TESTER_NAME)

clean_tester:
	rm -rf $(TESTER_OBJ_DIR)

fclean_tester:
	rm -f tests.sh
	rm -f $(TESTER_NAME)


clean: clean_tester
	rm -rf $(OBJ_DIR)

fclean: clean fclean_tester
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re fclean_tester clean_tester