# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/16 21:52:37 by ael-fadi          #+#    #+#              #
#    Updated: 2019/11/20 01:12:56 by ael-fadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS= ft_flag_c.c ft_flag_d_2.c ft_flag_d.c ft_flag_s_2.c ft_flag_s.c ft_flag_u_2.c ft_flag_u.c ft_flag_x_2.c \
	  ft_flag_x_3.c ft_flag_x.c ft_flag_xx_1.c ft_flag_xx_3.c ft_flag_xx.c ft_getflag.c ft_print_conv.c \
	  ft_printf_tools.c ft_printf_tools2.c ft_printf.c

OBJS= ft_flag_c.o ft_flag_d_2.o ft_flag_d.o ft_flag_s_2.o ft_flag_s.o ft_flag_u_2.o ft_flag_u.o ft_flag_x_2.o \
	  ft_flag_x_3.o ft_flag_x.o ft_flag_xx_1.o ft_flag_xx_3.o ft_flag_xx.o ft_getflag.o ft_print_conv.o \
	  ft_printf_tools.o ft_printf_tools2.o ft_printf.o

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRCS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

bonus:
		gcc -Wall -Wextra -Werror -c $(BSRCS)
		ar -rs $(NAME) $(BOBJS)
		ranlib $(NAME)

clean:
		rm -rf $(OBJS) $(BOBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
