# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 14:15:13 by jleem             #+#    #+#              #
#    Updated: 2021/01/08 15:00:47 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR)
LIBFLAGS	= -lm

AR			= ar
ARFLAGS		= -rcs

SRCDIR		= srcs/
INCDIR		= includes/

SRCS		= $(wildcard $(SRCDIR)*.c) # explicit (submodules)
OBJS		= $(SRCS:.c=.o)
NAME		= c-raytracer
MODULENAME	= $(addsuffix .a, $(NAME))

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(CC) $(CFLAGS) $^ main.c -o $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LIBFLAGS)

clean		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME) $(MODULENAME)

re			: fclean all

# module_		: CFLAGS += -g3 -fsanitize=address
module_		: CFLAGS += -O2
module_		: $(OBJS)
	$(AR) $(ARFLAGS) $(MODULENAME) $^
module		: fclean module_

.PHONY		: all clean fclean re module
