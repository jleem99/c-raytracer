# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 14:15:13 by jleem             #+#    #+#              #
#    Updated: 2021/01/14 12:11:49 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
override CFLAGS	+= -I$(INCDIR) -I$(LIBFTDIR)
# LIBFLAGS	= -lft -lm

AR			= ar
ARFLAGS		= -rcs

SRCDIR		= srcs/
INCDIR		= includes/

SRCS		= $(wildcard $(SRCDIR)*.c) # explicit (submodules)
OBJS		= $(SRCS:.c=.o)
NAME		= c-raytracer
MODULENAME	= $(addsuffix .a, $(NAME))

LIBFT			= $(addprefix $(LIBFTDIR), libft.a)
LIBFTDIR		= ../../Libft/

all			: $(NAME)

$(NAME)		: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ main.c -o $(NAME)

$(LIBFT)		:
	$(MAKE) -C $(LIBFTDIR) CC=clang CFLAGS=-O3 bonus

clean		:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean		: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME) $(MODULENAME)

re			: fclean all

module		: CFLAGS += -O3
module		: $(OBJS)
	$(AR) $(ARFLAGS) $(MODULENAME) $^

.PHONY		: all clean fclean re module
