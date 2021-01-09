# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 14:15:13 by jleem             #+#    #+#              #
#    Updated: 2021/01/10 03:13:54 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR)
LIBFLAGS	= -lft -lm

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
	$(MAKE) -C $(LIBFTDIR) bonus

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
