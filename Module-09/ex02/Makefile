NAME		=	PmergeMe

CC			:=	c++

CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98

SRCS		=	main.cpp PmergeMe.cpp

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
		@clear
		@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
		@make fclean
