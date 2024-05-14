# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 14:42:18 by tkitahar          #+#    #+#              #
#    Updated: 2024/05/14 16:19:09 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CCLFAGS = -Wall -Wextra -Werror
ARFLAGS = -rsc
CCDEBUGFLAGS = -g -fsanitize=address

OBJNAME = ft_printf \

OBJS = $(addsuffix .o, $(OBJNAME))


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) -c $(CCLFAGS) $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re

tst : $(OBJS)
	# $(CC) $(CCDEBUGFLAGS) $(CCLFAGS) $(OBJS)
	$(CC)  $(CCLFAGS) $(OBJS)
	./a.out
