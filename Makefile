# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 15:53:53 by tebatsai          #+#    #+#              #
#    Updated: 2019/07/08 16:52:29 by tebatsai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = *.c

OBJECTS = *.o

FLAGS = -Wall -Werror -Wextra

MLX = -L ft_libgfx/minilibx_macos_sierra -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all:$(NAME)

$(NAME):$(LIBFT) $(OBJECTS) 
	gcc $(FLAGS) $(MLX) *.c -o $(NAME) $(LIBFT) -g
$(OBJECTS):
	gcc $(FLAGS) -c *.c
norm:
	norminette *c *h
clean:
	make -C ./libft clean
	/bin/rm -f $(OBJECTS)

fclean: clean
	make -C ./libft fclean
	/bin/rm -rf $(NAME)
re: clean all
