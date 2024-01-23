NAME		=	scavtrap

CC			:=	c++

CXXFLAGS	:=	-Wall -Werror -Wextra -std=c++98

SRCS_F		=	srcs/

SRCS		=	main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS		=	$(addprefix $(SRCS_F), $(SRCS:%.cpp=%.o))

$(NAME):	$(OBJS)
			$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
