NAME		=	btc

CC			:=	c++

CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98

SRCS		=	main.cpp BitcoinExchange.cpp

OBJS		=	$(addprefix srcs/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
		@rm -rf $(OBJS)

fclean:	clean
		@rm -rf $(NAME)

re:		fclean all

test:
		@make re
		@./$(NAME) input.csv
		@make fclean
