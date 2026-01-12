NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \
	main.cpp
HEADERS = \
	Animal.hpp \
	Cat.hpp \
	Dog.hpp \
	WrongAnimal.hpp \
	WrongCat.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
