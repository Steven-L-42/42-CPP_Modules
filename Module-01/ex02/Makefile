# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slippert <slippert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 18:49:59 by slippert          #+#    #+#              #
#    Updated: 2023/12/03 20:19:22 by slippert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	zombie

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
