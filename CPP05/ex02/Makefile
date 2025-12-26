# =======================
# Project
# =======================
NAME        = test

# =======================
# Compiler
# =======================
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

# =======================
# Sources
# =======================
SRCS        = main.cpp \
              Bureaucrat.cpp \
              AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp

# =======================
# Objects
# =======================
OBJ_DIR     = obj/
OBJS        = $(SRCS:.cpp=.o)
OBJ_FILES   = $(addprefix $(OBJ_DIR), $(OBJS))

# =======================
# Dependency files (.d)
# =======================
DEPS        = $(OBJ_FILES:.o=.d)

# =======================
# Rules
# =======================
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile .cpp -> .o and generate .d
$(OBJ_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@
#-MMD   # generate .d file (dependency)
#-MP    # avoid error if header is deleted

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

# =======================
# Include dependencies
# =======================
-include $(DEPS)
#เครื่องหมาย - จะไม่ error ถ้ายังไม่มีไฟล์
#ทำให้ make อ่าน dependency graph จริง

.PHONY: all clean fclean re
