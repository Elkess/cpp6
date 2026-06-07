CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = reinterpret_cast

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Serializer.hpp Data.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean