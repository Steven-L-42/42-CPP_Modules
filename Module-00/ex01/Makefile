# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slippert <slippert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 18:49:59 by slippert          #+#    #+#              #
#    Updated: 2023/12/08 13:16:15 by slippert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phone

CC			=	c++

FLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS_F		=	srcs/

SRCS		=	main.cpp phoneBook.cpp Contact.cpp

OBJS		=	$(addprefix $(SRCS_F), $(SRCS:%.cpp=%.o))

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
