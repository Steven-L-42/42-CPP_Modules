NAME		=	interface

SRCS_F		=	srcs/

SRCS		=	main.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp

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