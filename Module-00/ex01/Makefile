CC = c++
CFLAGS = -Wall -Wextra -Werror
VFLAG = -std=c++98

SRC = PhoneBook.cpp Contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = awesomePhonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(VFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(VFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re megaphone