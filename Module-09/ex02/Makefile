CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -std=c++98

SRC = main.cpp PmergeMe.cpp PmergeMeVector.cpp PmergeMeDeque.cpp
BONUS_SRC = $(SRC) PmergeMeList.cpp

OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
NAME = PmergeMe

BONUS_OBJ = $(BONUS_SRC:%.cpp=%_bonus.o)
BONUS_DEP = $(BONUS_OBJ:.o=.d)
NAMEBONUS = PmergeMeBonus

all: $(NAME)
bonus: $(NAMEBONUS)

debug: CXXFLAGS += -g -DDEBUG
debug: clean $(NAME)

%_bonus.o: %.cpp
	$(CXX) $(CXXFLAGS) -DBONUS -c $< -o $@

$(NAMEBONUS): $(BONUS_OBJ)
	$(CXX) $(CXXFLAGS) $(VFLAG) $(BONUS_OBJ) -o $(NAMEBONUS)

bonusdebug: CXXFLAGS += -g -DDEBUG
bonusdebug: clean bonus

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(VFLAG) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ) $(DEP) $(BONUS_DEP)

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)

re: fclean all

-include $(DEP)
-include $(BONUS_DEP)

.PHONY: all clean fclean re debug bonus bonusdebug