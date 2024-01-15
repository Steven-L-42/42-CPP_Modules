NAME			=	Bureaucrat

COMPILE			=	c++

FLAGS			=	-Wall -Wextra -Werror -std=c++98

SRCS			=	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJS			=	$(addprefix srcs/, $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME):		$(OBJS)
				$(COMPILE) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

test:
				@make
				@rm -rf $(OBJS)
				@clear
				@./Bureaucrat
