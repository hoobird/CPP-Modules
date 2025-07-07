CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(VFLAG) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re