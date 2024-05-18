# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkitahar <tkitahar@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 14:42:18 by tkitahar          #+#    #+#              #
#    Updated: 2024/05/18 19:43:28 by tkitahar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILENAME = ft_printf \
			ft_putchar \
			ft_putstr \
			ft_putaddress \
			ft_putnbr

OBJS = $(addprefix objs/, $(addsuffix .o, $(FILENAME)))
SRCS = $(addprefix srcs/, $(addsuffix .c, $(FILENAME)))

LIBFT_DIR = ./libft
LIBFTA = $(LIBFT_DIR)/libft.a

CCLFAGS = -Wall -Wextra -Werror
ARFLAGS = -rsc
CCDEBUGFLAGS = -g -fsanitize=address
INCLUDES = -I includes

all : $(NAME)

$(NAME) : $(LIBFTA) $(OBJS)
	cp $(LIBFTA) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFTA):
	make -C $(LIBFT_DIR)

objs/%.o : srcs/%.c
	@if [ ! -d "objs" ]; then\
		mkdir objs;\
	fi
	@if [ ! -f "includes/libft.h" ]; then\
		cp libft/includes/libft.h includes/libft.h;\
	fi
	$(CC) $(CCLFAGS) $(INCLUDES) -c $< -o $@

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJS)

fclean : clean
	$(RM) $(NAME) $(LIBFTA)

re : fclean all

.PHONY : all, clean, fclean, re

tst : $(LIBFTA) $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CCDEBUGFLAGS)   $(OBJS) $(LIBFT)$(LIBFTA)
	./a.out


debug : $(LIBFTA) $(SRCS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CCDEBUGFLAGS) $(SRCS) $(LIBFT)$(LIBFTA) $(INCLUDES)
	./a.out
