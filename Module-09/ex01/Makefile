NAME		=	RPN

CXX			:=	c++

CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98 -g

SRCS		=	main.cpp RPN.cpp

OBJS		=	$(addprefix srcs/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

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
