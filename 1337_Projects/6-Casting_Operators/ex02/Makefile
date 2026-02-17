NAME = base
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Base.cpp 
OBJ = $(SRC:%.cpp=%.o)
HDR = Base.hpp A.hpp B.hpp C.hpp 

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) 

%.o:%.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(OBJ)
fclean: clean
	rm $(NAME)
re: fclean $(NAME)
.PHONY: clean fclean re all 