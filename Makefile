# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 14:57:53 by ddevico           #+#    #+#              #
#    Updated: 2015/12/02 17:55:01 by ddevico          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MKEX = gcc -o
COMP = gcc -c
AR = ar -rc

SOURCE =ft_printf.c ft_putchar.c ft_putstr.c ft_printnbr.c ft_strlen.c \
		ft_itoa.c ft_strdup.c ft_printchar.c ft_printstr.c ft_printunsigned.c \
		ft_utoa.c ft_printhexa.c ft_hexatoa.c ft_printvoid.c ft_printoct.c \
		ft_octtoa.c ft_toupper.c ft_printloct.c ft_printlong.c ft_printlnbr.c \
		ft_putw.c ft_printwstr.c ft_printwchar.c ft_wstrlen.c ft_newflag.c \
		ft_parseflag.c ft_checknumber.c ft_atoi.c ft_checkspace.c ft_putflag.c \
		ft_strchr.c ft_putspecial.c ft_putflagspecial.c ft_error.c \
		ft_printpourcent.c ft_util.c

FLAGS = -W -Wall -Wextra
OBJECT = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	@$(AR) $(NAME) $(OBJECT)
	@ranlib $(NAME)
	#gcc $(FLAGS) -c $(SOURCE)
	#gcc -o $(NAME) $(OBJECT) $(FLAGS) -g

$(OBJECT) :
	@$(COMP) $(SOURCE) $(FLAGS)
	@echo "\033[33mCompilation OK\033[0m"

clean :
	@/bin/rm -f $(OBJECT)
	@echo "\033[33mObject deleted\033[0m"


fclean : clean
	@/bin/rm -f $(NAME)
	@echo "\033[33mExec deleted\033[0m"

re : fclean all
