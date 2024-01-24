NAME		=	stl

CXX			:=	c++

CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98

SRCS		=	main.cpp

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
		@make
		@clear
		@./$(NAME)
		@make fclean
