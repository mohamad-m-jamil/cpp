NAME    = violence
CXX     = c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
SRC_DIR = src
SRC     = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/Weapon.cpp \
          $(SRC_DIR)/HumanA.cpp \
          $(SRC_DIR)/HumanB.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re