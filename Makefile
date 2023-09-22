# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meacar <meacar@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 05:00:17 by meacar            #+#    #+#              #
#    Updated: 2023/01/15 05:01:08 by meacar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc 
SRCS= $(wildcard ./sources/*.c)
MFLAGS=./mlxlib/libmlx.a
AFLAGS = -Wall -Werror -Wextra -O3 -I./mlxlib
RM = rm -rf
OBJS = $(SRCS:.c=.o)



all: $(MFLAGS) $(NAME) 

$(MFLAGS):
	make -C ./mlxlib

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(MFLAGS) -Imlx -framework OpenGL -framework AppKit -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(SRCS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean: clean
	$(RM) $(NAME)

norm:
	norminette $(wildcard ./sources/*.c) $(wildcard ./headers/*.h)

clean:
	make clean -C ./mlxlib
	$(RM) ./*.o

re: fclean all

.PHONY : all fclean clean re