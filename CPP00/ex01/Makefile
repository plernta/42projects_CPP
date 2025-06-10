NAME = phonebook
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJ = $(SRC:%.cpp=%.o)
COMPILE = c++

all: $(NAME)
$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re