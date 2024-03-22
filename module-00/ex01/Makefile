COMPILER = c++
FLAGS = -Wall -Wextra -Werror

NAME = awesome_phonebook

SRCS = awesome_phonebook.cpp \
	Contact.cpp \
	PhoneBook.cpp \

HEADERS = awesome_phonebook.h \
	Contact.hpp \
	PhoneBook.hpp \

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADERS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re