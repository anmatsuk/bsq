# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatsuk <matsuknastya@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 13:37:05 by amatsuk           #+#    #+#              #
#    Updated: 2017/04/24 16:40:27 by amatsuk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PNAME = bsq
INCLUDE = includes/
FILES = srcs/
OBJECTS = *.o

.PHONY: all clean fclean re

all: compile
	@gcc -o $(PNAME) -Wall -Wextra -Werror main.c -O3 -I$(INCLUDE) $(OBJECTS)

compile:
	@gcc -I$(INCLUDE) -Wall -Wextra -Werror -c -O3 $(FILES)*.c
	
clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(PNAME)

re: fclean all
