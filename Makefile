# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/22 17:06:10 by jealonso          #+#    #+#              #
#    Updated: 2015/02/27 19:18:16 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFTPATH	=	libft

LIBFT	=	$(LFTPATH)/libft.a

INCLPATH =	includes

OBJSPATH =	objs

SRCSPATH =	srcs

CC = gcc $(CMLX)

CFLAGS = -Wall -Werror -Wextra -I $(INCLPATH) -I $(LFTPATH)/$(INCLPATH)

CMLX = -L/usr/X11/lib -lmlx -lXext -lX11

LDFLAGS	= -L $(LFTPATH) -lft

NAME = fdf

SRCS = \
		main.c \
		ft_error.c\
		get_next_line.c\
		ft_get_map.c\
		ft_aff.c

OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

HFILES = fdf.h

HEAD = $(patsubst %.h, includes/%.h, $(HFLIES))

all: $(OBJSPATH) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJSPATH)

fclean: clean
	$(MAKE) -C $(LFTPATH) fclean
	rm -f $(NAME)

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

cleanall: clean cleanlib

re: fclean all

$(OBJSPATH):
	mkdir $@

$(LIBFT):
	$(MAKE) -C $(LFTPATH)

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
	@echo "Pouet"
