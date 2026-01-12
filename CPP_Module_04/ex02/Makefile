NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = \
	Animal.cpp \
	Brain.cpp \
	Dog.cpp \
	Cat.cpp \
	main.cpp
HEADERS = \
	Animal.hpp \
	Brain.hpp \
	Dog.hpp \
	Cat.hpp
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
