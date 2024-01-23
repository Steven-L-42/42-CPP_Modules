# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slippert <slippert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 18:49:59 by slippert          #+#    #+#              #
#    Updated: 2024/01/23 18:45:20 by slippert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fixed

CC			:=	c++

CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Fixed.cpp

SRCS_FOLDER =	srcs/

OBJS		=	$(addprefix $(SRCS_FOLDER),$(SRCS:%.cpp=%.o))

$(NAME):	$(OBJS)
			$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
