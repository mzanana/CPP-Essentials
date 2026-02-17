NAME = serializer
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Serializer.cpp 
OBJ = $(SRC:%.cpp=%.o)
HDR = Data.hpp Serializer.hpp 

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