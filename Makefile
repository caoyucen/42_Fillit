# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycao <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 11:40:20 by ycao              #+#    #+#              #
#    Updated: 2017/01/23 13:44:16 by ycao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = *.c

HEADER = *.h


all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	gcc -Wall -Wextra -Werror *.o -o $(NAME) main.c


clean:
	/bin/rm -f *.o *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
