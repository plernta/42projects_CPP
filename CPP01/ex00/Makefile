NAME = zombie
FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = g++
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJS)
	@$(COMPILE) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	@$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re