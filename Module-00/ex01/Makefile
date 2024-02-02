# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slippert <slippert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 18:49:59 by slippert          #+#    #+#              #
#    Updated: 2024/02/01 16:30:36 by slippert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phone

CXX			:=	c++

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS_F		=	srcs/

SRCS		=	main.cpp phoneBook.cpp Contact.cpp

OBJS		=	$(addprefix $(SRCS_F), $(SRCS:%.cpp=%.o))

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
