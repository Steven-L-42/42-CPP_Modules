NAME		=	convert

CC			=	c++

CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRCS		=	main.cpp ScalarConverter.cpp ConvertHelper.cpp

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
		@make
		@./$(NAME)
		@make fclean
