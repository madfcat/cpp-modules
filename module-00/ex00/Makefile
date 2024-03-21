
COMPILER = c++
FLAGS = -Wall -Wextra -Werror

NAME = megaphone

SRCS = megaphone.cpp
OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(SRCS)
	mkdir -p $(OBJ_DIR)
	$(COMPILER) $(FLAGS) -c $(SRCS) -o $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re