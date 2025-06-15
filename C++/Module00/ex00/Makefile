CC = g++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJ = megaphone.o
TARGET = megaphone

all: $(TARGET)

$(OBJ): $(SRC)
	$(CC) $(CCFLAGS) -c $(SRC)

$(TARGET): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(TARGET)

clean:
	@if [ -f $(OBJ) ]; then \
		rm -f $(OBJ); \
		echo "Object file cleaned."; \
	else \
		echo "No object file to remove."; \
	fi

fclean: clean
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo "Executable cleaned."; \
	else \
		echo "No executable to remove."; \
	fi

re: fclean all

.PHONY: all clean fclean re
