NAME = test
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp
OBJ = $(SRCS:.cpp=.o)
OBJ_DIR = obj/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

