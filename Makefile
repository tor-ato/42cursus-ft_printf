# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 14:42:18 by tkitahar          #+#    #+#              #
#    Updated: 2024/05/17 17:47:54 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CCLFAGS = -Wall -Wextra -Werror
ARFLAGS = -rsc
CCDEBUGFLAGS = -g -fsanitize=address
LIBFT = libft/
LIBFTA = libft.a

OBJNAME = ft_printf \
			ft_putchar \
			ft_putstr \
			ft_putaddress \
			ft_putnbr \
			$(addprefix $(LIBFT), $(OBJNLIBFT))

OBJS = $(addsuffix .o, $(OBJNAME))


all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	$(AR) $(ARFLAGS) $@ $^ $(LIBFT)$(LIBFTA)

%.o : %.c
	$(CC) -c $(CCLFAGS) $^

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re

tst : $(OBJS)
	@make -C libft
	$(CC) $(CCLFAGS) $(OBJS) $(LIBFT)$(LIBFTA)
	./a.out
