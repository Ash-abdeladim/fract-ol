# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdelad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/23 22:43:02 by aabdelad          #+#    #+#              #
#    Updated: 2022/04/23 22:43:07 by aabdelad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ = main.o \
	  utils.o \
	  event.o \
	  zoom.o \
	  utils_extra.o \
	  random_colors.o 

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
