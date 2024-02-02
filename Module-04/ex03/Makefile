NAME		=	interface

SRCS_F		=	srcs/

SRCS		=	main.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp

OBJS		=	$(addprefix $(SRCS_F), $(SRCS:.cpp=.o))

CXX			:=	c++

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all