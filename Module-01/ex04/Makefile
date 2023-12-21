# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slippert <slippert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 18:49:59 by slippert          #+#    #+#              #
#    Updated: 2023/12/04 10:43:49 by slippert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	replace

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Replace.cpp

SRCS_FOLDER =	srcs/

OBJS		=	$(addprefix $(SRCS_FOLDER),$(SRCS:%.cpp=%.o))

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
