CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = functions.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = dynamic_cast

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean