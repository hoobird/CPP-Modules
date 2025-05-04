CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD
VFLAG = -std=c++98

SRC = main.cpp Bureaucrat.cpp Form.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
NAME = gahmentoo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(VFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(VFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re