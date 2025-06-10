NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Megaphone.cpp
OBJ = $(SRC:.cpp=.o)
COMPILE = c++

all: $(NAME)
$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $(SRC) -o $(NAME)
$(OBJ): $(SRC)
	$(COMPILE) $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re