CC = g++
CFLAGS = -Wall -Wextra -Werror

SRC = src/phonebook.cpp src/main.cpp src/contact.cpp
OBJ = src/phonebook.o src/main.o src/contact.o
TARGET = phonebook

all: $(TARGET)

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ)
	echo "Object files cleaned."

fclean: clean
	rm -f $(TARGET)
	echo "Executable cleaned."

re: fclean all

.PHONY: all clean fclean re
