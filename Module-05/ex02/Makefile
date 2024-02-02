NAME			=	Bureaucrat

CXX					:=	c++

CXXFLAGS		:=	-Wall -Wextra -Werror -std=c++98

SRCS			=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS			=	$(addprefix srcs/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME):		$(OBJS)
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

