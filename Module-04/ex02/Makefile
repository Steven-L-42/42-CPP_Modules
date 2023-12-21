NAME		=	abstract

SRCS_F		=	srcs/

SRCS		=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJS		=	$(addprefix $(SRCS_F), $(SRCS:.cpp=.o))

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all