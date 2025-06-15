CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes
SRC = src/Animal.cpp src/Dog.cpp src/Cat.cpp src/WrongAnimal.cpp src/WrongCat.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = polymorphism

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
